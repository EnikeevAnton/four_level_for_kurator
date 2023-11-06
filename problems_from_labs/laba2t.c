#include <stdio.h>

int main()
{
    int arr[15], i = 0;
    char end;
    do{
        scanf("%d%c", &arr[i++], &end);
    }while(end != '\n');
    
    int len = i, a, b;
    int arr2[len];
    arr2[0] = arr[1];
    arr2[len - 1] = arr[len - 2];
    for (int i = 1; i < len - 1; i++){
        a = arr[i + 1];
        b = arr[i - 1];
        if (a > 0 && b > 0 || a < 0 && b < 0){
            arr2[i] = b - a;
        }else{
            arr2[i] = a + b;
        }
    
    }
    for (i = 0; i < len; i++){
        printf("%d  ", arr2[i]);
    }
    return 0;
}

