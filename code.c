#include <stdio.h>
#include <limits.h>
int main()
{
	int i = 0, arr_len;
	float arr[20], max_res = 0, time;
	char end_line;

	do{
		scanf("%f%c", &arr[i], &end_line);
		i++;
	}while(i < 100 && end_line != '\n');
        arr_len = i;

	for (i = 0; i < arr_len; i++){
		if (arr[i] < 0){
			time = -1 * arr[i];
		}else{
			time = arr[i];
		}
		if (time > max_res){
			max_res = time;
		}
	}
        printf("%f", max_res);   


        return 0;
}	







