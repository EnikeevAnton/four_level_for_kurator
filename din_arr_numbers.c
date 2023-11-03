#include <stdlib.h>
#include <stdio.h>

int main(){
    int tim = 64; //память
    int nch = 0;
    char end;
    int *arr = malloc(64 * sizeof(int));
    if (arr == NULL){
        fprintf(stderr, "out of memory\n");
        exit(1);
    }
    do{
       if (nch >= tim - 1)
        {
            tim += 1;
            arr = (int *)realloc(arr, tim);
            
            if (arr == NULL)
            {
                fprintf(stderr, "out of memory\n");
                exit(1);
            }
        }
        scanf("%d%c", &arr[nch], &end);
        nch++;
    }while(end != '\n');
    
    for (int i = 0; i < nch; i++){
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}
