#include<stdio.h>
#include<stdlib.h>
void input(char* str[], int* n, int *i);

int main(){
	int i = 0;
	int n = 0;
	char str[n][i]; //попробовать str[][]
	char new_str[n][i];
	input(str, &n, &i);
	printf("%s", str[n][i]);
	free(str);
	return 0;
}

void input(char* str[], int* n, int *i) {

	for (str[n][i]; str[n][i] != '\n'; *n++){
		do {
		scanf("%c", &str[n][i]);
		i++;
	} while (str[n][i-1] != ' ');
		
		str[n][i-1] = '\0';}

}