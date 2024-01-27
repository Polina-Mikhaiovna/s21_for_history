#include<stdio.h>
#include<math.h>

int main() {
	float rad = 57.29;
	int n;
	scanf("%d", &n);
	float a = (float)n;
	float res = a * rad;
	printf("%f\n", res);
	round(res);
	printf("round_res = %.f\n", res);

	return 0;
}
