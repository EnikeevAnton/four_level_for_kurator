#include <stdio.h>

int main(){
    int arr[10], len, i = 0;
    char end;
    do{
        scanf("%d%c", &arr[i++], &end);
    }while( end != '\n');
    len = i;
    int count = 0, sum = 0;
    
    for (int i = len - 1; i >= 0; --i){
        if (arr[i] % 2 != 0){
            printf("%d ", arr[i] * arr[i]);
            count += 1;
            sum += arr[i];
            }
    }
    printf("\nколичество-%d сумма-%d", count, sum);
    return 0;
}
