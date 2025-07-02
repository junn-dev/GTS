#include <stdio.h>
#include <math.h>

// f(x)
double f(double x) {
    return 3 * pow(x, 5) + 6 * x - 10;
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
    double saiso;
    int count = 0;
    do {
        c = (a + b) / 2; // tao ra khoang phan ly nghiem moi
        saiso = fabs(b - a);

        if (f(c) * f(a) > 0)
            a = c; // f(a0) * f(c0) < 0 => (a0, c0)
        else
            b = c; // f(b0) * f(c0) < 0 => (c0, b0)

        printf("Lan %d:\t x = %.6lf \t f(x) = %.6lf \t sai so: %.6lf\n", count, c, f(c), saiso);
        count++;
    } while (saiso >= eps);

    printf("\nNghiem gan dung: %.6lf\n", c);

    return 0;
}

