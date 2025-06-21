#include <stdio.h>
#include <math.h>

#define f(x) pow(sin(x), 4) + x * x * x

int main() {
    int n;
    double a, b;

    printf("Nhap can duoi a, can tren b va so doan n: ");
    scanf("%lf %lf %d", &a, &b, &n);

    double h = (b - a) / n;
    double s = f(a) + f(b);

    int i;
    for (i = 1; i < n; i++) {
        double x = a + i * h;
        s += 2 * f(x);
    }

    s = (h / 2) * s;

    printf("Gia tri tich phan theo cong thuc hinh thang = %.6lf\n", s);

    return 0;
}

