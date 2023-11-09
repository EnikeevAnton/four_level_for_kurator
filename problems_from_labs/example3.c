#include <stdio.h>
#include <wchar.h>

int main(){
    wchar_t str[101], c;
    int i = 0;
    c = getwchar();
    while (c != '\n'){
        if (!(c >= 'A' && c <= 'Z')){
            str[i++] = c;
        }
        c = getwchar();
    }
    printf("%ls", str);
}
