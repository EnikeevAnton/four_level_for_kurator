#include <stdio.h>
#include <stdlib.h>
int main(){
    int n;
    scanf("%d", &n);
    
    char **mas = malloc(sizeof(char*)*n);
    
    for (int i = 0; i <= n; i++){
        mas[i] = malloc(sizeof(char)*101);
        fgets(mas[i], 101, stdin);
    }
    
    int max_words = 0, number = 0;
    
    for (int i = 0; i <= n; i++){
        int j = 0, pr = 1;
        char *s = mas[i];
        
        while (s[j] != '\0' && s[j] != '.'){
            if (s[j] == ' ') {pr += 1;}
            j += 1;
        }
        if (pr > max_words){
            max_words = pr;
            number = i;
        }
    }
    printf("%d: %s\n", max_words, mas[number]);
    return 0;
}
