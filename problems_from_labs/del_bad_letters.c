#include <stdio.h>

int main() {
    int k = 0; 
    int i = 0; 
    int flag = 1; 
    char s[100]; 
    char s2[100]; 
    char digits[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    fgets(s, 100, stdin); 
    for (; (s[i] != '\n') && (s[i]); i++) {
        flag = 1; // Присвоение флагу значения 1 перед каждой итерацией внешнего цикла
        for (int j = 0; j < 26; j++) { 
            if (s[i] == digits[j]) {
                k++; 
                flag = 0; 
            }
        }
        if (flag) {
            s2[i - k] = s[i];
        }
    }
    s2[i - k] = '\0'; 
    printf("%s", s2); 
    return 0; 
}  
