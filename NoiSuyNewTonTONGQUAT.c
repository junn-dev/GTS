#include <stdio.h>

#define MAX 100

int main() {
    int n, i, j;
    double x[MAX], y[MAX], diff[MAX][MAX], xp, result, term;


    printf("Nhap so diem: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("x[%d] = ", i);
        scanf("%lf", &x[i]);
        printf("y[%d] = ", i);
        scanf("%lf", &y[i]);
        diff[i][0] = y[i];
    }

    for (j = 1; j < n; j++) {
        for (i = 0; i < n - j; i++) {
            diff[i][j] = (diff[i + 1][j - 1] - diff[i][j - 1]) / (x[i + j] - x[i]);
        }
    }

    printf("Nhap gia tri x can noi suy: ");
    scanf("%lf", &xp);

    result = diff[0][0];
    term = 1.0;
    for (i = 1; i < n; i++) {
        term *= (xp - x[i - 1]);
        result += term * diff[0][i];
    }

    printf("Gia tri noi suy tai x = %.6lf la y = %.6lf\n", xp, result);

    return 0;
}

