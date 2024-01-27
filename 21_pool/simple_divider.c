#include<stdio.h>
#include<stdlib.h>

int simple_div(int temp);
int divv(int temp, int d, int* x);

int main() {
	int temp;
	scanf("%d", &temp);
	int d = simple_div(temp);
	printf("simple_div = %d\n", d);
	return 0;
}

int simple_div(int temp) {
	
	int d = 2;
	int x = 0;

	while (d < temp && temp != 1) {
		if (divv(temp, d, &x) == 0) {
			temp = x;
			printf("1temp = %d\n", temp);}
		else d++;
	}
	return temp;
}

int divv(int temp, int d, int* x) { // prinimaet chislo i delitel

	printf("temp = %d, d = %d\n", temp, d);
	int error = 0;
	*x = 0;

	while (temp != 0) {
		if (temp < d) {
			error = 1;
		    break;
		} else {
			temp -= d;
		    *x = *x + 1;
 			//printf("x = %d, temp = %d\n", *x, temp);
 		}
	}
	
	printf("err = %d\n", error);
	return error;

}