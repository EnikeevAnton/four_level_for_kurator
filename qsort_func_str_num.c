#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sort_numbers(const void *a, const void *b);
int sort_str(const void *a, const void *b);

int main(){
    int arr_n[] = {2, 4, 1, 7, 8, 15, 3};
    char *arr_str[] = {"fn", "bm", "as", "lp", "md"};
    qsort(arr_n, 7, sizeof(int), sort_numbers); 
    /*параметры: 1 - указатель на первый элемент массива, 2 - кол-во элементов в соритруемом массиве, 3 - размер одного элемента масс. в байтах, 4 - функция, которая сравнивает 2 элемента;*/
    for (int i = 0; i < 7; i++){
        printf("%d ", arr_n[i]);
    }
    printf("\n");
    qsort(arr_str, 5, sizeof(char*), sort_str); //передаём размерность указателя, поскольку массив указателей, строки сортрирует в алфовитном порядке
    for (int i = 0; i < 5; i++){
        printf("%s ", arr_str[i]);
    }
    return 0;
}
    
int sort_numbers(const void *a, const void *b){
    int x = *(int *)a;
    int y = *(int *)b;
    return x - y; //в порядке возрастания, в порядке убвания: y - x
}

int sort_str(const void *a, const void *b){
    char **x = (char**)a;
    char **y = (char**)b;
    return strcmp(*x, *y);
}
