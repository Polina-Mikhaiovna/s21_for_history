#include <stdio.h>
#include <math.h>
//умножение двух квадратныхматриц

int main() {
    
    int n;
    int i, j, h;

    if(scanf("%d", &n) == 0) {
        printf("n/a");
        return 0; }

    int a[n][n], b[n][n], c[n][n];
  

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]); }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &b[i][j]); }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) { 
            c[i][j] = 0;}

    for(h = 0; h < n; h++) {
        c[i][j] = a[i][h]*b[h][j]; }
    }
        
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf((j == n - 1) ? "%d":"%d ", c[i][j]); 
        } printf("\n");
    }
}

