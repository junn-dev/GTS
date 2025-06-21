#include <stdio.h>
#include <math.h>

double f(double x) {
    return sqrt(x) + sin(x) - 10;
}

int main() {
    double a, b, eps;
    printf("Nhap a, b, eps: ");
    scanf("%lf %lf %lf", &a, &b, &eps);

    if (f(a) * f(b) >= 0) {
        printf("Khoang [%.2lf, %.2lf] khong thoa dieu kien f(a) * f(b) < 0\n", a, b);
        return 1;
    }

    double c;
    int count = 1;
    do {
        c = (a + b) / 2;

        if (f(c) * f(a) > 0)
            a = c;
        else
            b = c;

        double saiso = fabs(b - a);
        printf("Lan %d:\t x = %.6lf \t f(x) = %.6lf \t sai so: %.6lf\n", count, c, f(c), saiso);
        count++;
    } while (fabs(b - a) >= eps);

    printf("\nNghiem gan dung: %.6lf\n", c);

    return 0;
}

