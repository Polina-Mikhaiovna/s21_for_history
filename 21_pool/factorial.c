//factorial

#include<stdio.h>
#include<stdlib.h>
void input(int *n);
int factorial(int n);
 
int main() {
    int n;
    input(&n);
   int a;
    for (int k = 0; k <= (n - 1); k++) {
        a = factorial(n)/(factorial(k) * factorial(n - k));
        printf("%d ", a);
    }
    a = factorial(n)/(factorial(n) * factorial(0));
    printf("%d", a);
        return 0;
    }
 
void input(int *n) {
    char k;
    if (scanf("%d%c", n, &k) != 2 || k != '\n') {
       printf("n/a");
       exit(1);
    }
}
 
int factorial(int n) {
    int a = 1;
    for (int i = 1; i <= n; i++) {
        a = a * i;
    }
    return a;
}