#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define STEP_S 20
#define N 20

void free_memory(char **text, int max_count_string){
    for (int i = 0; i < max_count_string; i++){
        free(text[i]);
    }
    free(text);
    return;
}

void checkNull(char **text, int max_count_string, void *ptr){
    if (ptr == NULL){
        free_memory(text, max_count_string);
        fprintf(stderr, "Memory Allocation Error\n");
        exit(1);
    }
}

char **read_text(int *count_sents,int *max_count_string){
      char **text = malloc(sizeof(char*) * N);
      if (text == NULL){
          fprintf(stderr, "Memory Allocation Error\n");
          exit(1);
      }
      for (int k = 0; k < N; k++){
          text[k]= malloc(sizeof(char) * STEP_S);
          checkNull(text, k, text[k]);
      }
      char c;
      int j = 0, end_is_newline = 0, count_end = 0;
      while(count_end < 2){
          int i = 0, size = STEP_S;
          int is_start_sent = 1;
          do{
              if (i % STEP_S == STEP_S - 1){
                  size += STEP_S;
                  char *test = text[j];
                  test = (char*)realloc(test, (size) * sizeof(char));
            	  checkNull(text, *max_count_string, test);
                  text[j] = test;
              }
              c = getchar();
              if (is_start_sent){
                  if (isblank(c)){ 
                      continue;
                  }else{is_start_sent = 0;}
              }
              text[j][i] = c;
              i++;
    
         }while(c != '.' && c != '\n');
         
         if (i > 1 && text[j][i - 1] == '\n'){
             end_is_newline = 1;
             text[j][i - 1] = '.';
         }else if(i > 2 && text[j][i - 1] != '\n'){
             end_is_newline = 0;
         }
         text[j][i] = '\0';
         if(text[j][0] == '\n'){
             count_end++;
         }else{
             count_end = 0;
             j++;
         }
         if (count_end == 1 && end_is_newline){
             break;
         }
         if (j % N == 0){
             *max_count_string = *max_count_string + N;
             char **test = text;
             test = (char **)realloc(text, *max_count_string * sizeof(char *));
             checkNull(text, *max_count_string, test); 
             text = test;
             for (int f = j; f < *max_count_string; f++){
                 text[f] = malloc(sizeof(char) * STEP_S);
                 checkNull(text, f, text[f]);
             }
         }
      }
      text[j][0] = '\0';
      *count_sents = j;
      return text;
}
char **del_identical_sents(char **text, int max_count_string, int *count_sent){
    int i = 0;
    while (i < *count_sent){
        int j = i + 1;
        while (j < *count_sent){
            if (strcasecmp(text[i], text[j]) == 0){
                for (int k = j; k < *count_sent - 1; k++){
                    if (strlen(text[k]) < strlen(text[k+1])){
                        char *test;
                        test = (char *)realloc(text[k], (strlen(text[k+1] + 1) * sizeof(char)));
                        checkNull(text, max_count_string, test);
                        text[k] = test;
                        strcpy(text[k], text[k+1]);

                    }else{
                        strcpy(text[k], text[k+1]);
                    }
                }
                text[*count_sent - 1][0] = '\0';
                *count_sent = *count_sent - 1;
            }else{ 
                j++;
                
             }
            }
        i++;
        }

        return text;
}
void out(char **text, int count_sents){
    for (int j = 0; j < count_sents; j++){
        printf("%d) %s\n",j, text[j]);
    }
    return;
}
int main(){
    int count_sents = 0;
    int max_count_string = N;
    char **s = read_text(&count_sents, &max_count_string);
    del_identical_sents(s, max_count_string, &count_sents);
    out(s, count_sents);
    /*int k = 5;
    for (int i = 0; i < k; i++){
        printf("%s\n", s[i]);
    }*/
    return 0;
}


