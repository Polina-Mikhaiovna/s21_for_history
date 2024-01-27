#include<stdio.h>
#include<stdlib.h>

void output(int* arr, int *count);
void input(int* arr, int *count);

int main() {
	int count;
	int* arr = NULL;
	input(arr, &count);
	output(arr, &count);
	free(arr);
	return 0;
}

void input(int* arr, int *count) {
	int i = 0;
	for(int i = 0; ; i++) {
		arr = (int*)realloc(arr, (i+1) * sizeof(int));
		scanf("%d", (arr + i));
		if (*(arr + i) == -1){
		break;}
		printf("%d", i);
	} *count = i;
}

/*int input(int *array, int *n) {
    int test = 1;
    int scn = 0;
    for (int i = 0; ; i++) {
        array = realloc(array, (i+1)*sizeof(int));
        scn = scanf("%d", &array[i]);
        if (scn == 1) {
            *n = i;
            if (array[i] == -1) {
            break;
            }
        } else {
            test = 0;
            break;
        }
    }
    return test;
}
*/


void output(int* arr, int *count) {
	for (int i = 0; i < *count-1; i++)
		printf("%d", *(arr + i));
}