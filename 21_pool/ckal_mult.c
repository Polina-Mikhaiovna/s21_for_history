#include<stdio.h>


int main(){


	unsigned int n = 0;
	unsigned int a[n];
	unsigned int b[n];
	unsigned int res = 0;
	unsigned int i = 0;
	
	scanf("%d", &n);
		
	do {
		scanf("%d", &a[i]);
		printf("%d ", a[i]);
		i++;
	} while (i < n);

		i = 0;
	
	do {
		scanf("%d", &b[i]);
		printf("%d ", b[i]);
		i++;
	} while (i < n);

	for (int i = 0; i < n; i++) {
		res += a[i] * b[i];
		printf("\n%d\n", res);
	}
	return 0;
}