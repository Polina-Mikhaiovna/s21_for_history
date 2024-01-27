#include <stdio.h>
#include <math.h>

//double aniezi();
//double bernulli();
void giperbola();
void output();

int main() {

	double pi = 3.141592654;
	double step = 0.14959965;
	double x;
	
	for(x = -3.141592654; x <= pi; x + step) {
		printf("%.7lf|", x);
//		double aniezi(x);
//		double bernulli(x);
		if (x == 0){
			printf("-");
		}
		else {
			giperbola(x);
			printf("\n");
		}
	} return 0;
}

void output(double y) {

	printf("%.7lf|", y);
}

void giperbola(double x) {
	double y;

	
		y = 1/(x*x);
		output(y);
	}