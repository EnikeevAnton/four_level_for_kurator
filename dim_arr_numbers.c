#include <stdio.h>
#include <stdlib.h>

void* checkNull(void* ptr){ //проверяем, что не произошло ошибки при выделении памяти
    if (ptr == 0){
        fprintf(stderr, "Out of memory\n");
        exit(1);
    }
    return ptr;
}

int* readDynamicArr(int* capacityPlace, int* lenPlace){ //считывание в массив
    int* arr = checkNull(malloc(1*sizeof(int)));
    int capacity = 1;
    int len = 0;
    char end;
    while (1){
        scanf("%d%c", &arr[len++], &end);
        if (end == '\n'){
            break;
        }
        if (len == capacity){
            capacity *= 2;
            arr = checkNull(realloc(arr, capacity * sizeof(int)));
        }
    }
    *capacityPlace = capacity; 
    *lenPlace = len;
    return arr;
}

int main(){ //проверяем, что всё работает, освобождаем память
   int capacity;
   int len;
   int* arr = readDynamicArr(&capacity, &len);
   printf("объем - %d; длина - %d;\n", capacity, len);
   for (int i = 0; i < len; i++){
       printf("%d ", arr[i]);
   }
   free(arr);
}

