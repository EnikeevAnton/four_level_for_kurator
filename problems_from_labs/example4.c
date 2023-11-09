#include <stdio.h>

int main(){
    unsigned int a, b;
    int count = scanf("%x%x", &a, &b);
    if (count < 2) {printf("error: %d", count);}
    else {printf("%o", a + b);}
    return 0;
}
   
