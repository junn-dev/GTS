#include <stdio.h>
#include <math.h>

#define MAX 100

double fx(double x) {
    return pow(2, x) / (x * x + 1); 
}

int main() {
    int n, i, j;
    double x[MAX], y[MAX];
    
    printf("Nhap so diem n: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("x[%d] = ", i);
        scanf("%lf", &x[i]);
        
        // Neu nhap y(x) theo bang
        printf("y[%d] = ", i);
        scanf("%lf", &y[i]);
        
        // Neu tinh theo f(x)
//        y[i] = fx(x[i]);
//        printf("y[%d] = f(%.2lf) = %.6lf\n", i, x[i], y[i]);
    }

    double x_noi_suy;
    printf("Nhap gia tri x can noi suy: ");
    scanf("%lf", &x_noi_suy);

    double result = 0.0;

    for (i = 0; i < n; i++) {
        double term = y[i];
        for (j = 0; j < n; j++) {
            if (j != i) {
                term *= (x_noi_suy - x[j]) / (x[i] - x[j]);
            }
        }
        result += term;
    }
    
    printf("Gia tri noi suy tai x = %.2lf la y = %.6lf\n", x_noi_suy, result);

    return 0;
}

