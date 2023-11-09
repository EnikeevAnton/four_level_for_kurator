#include <stdio.h>
int main(){
    int n, i = 0;
    scanf("%d", &n);
    long long int arr[100], res;
    char end;
    do{
        scanf("%lld%c", &arr[i], &end);
        i++;
    }while (i < n);
    
    for (int i = 0; i < n; i += 2) {res += arr[i];}
    printf("%lld", res);
    return 0;
}
