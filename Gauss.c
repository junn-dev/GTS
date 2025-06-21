#include <stdio.h>
#include <math.h>

#define f1(x, y, z)  (3 - 1 * y + 1 * z) / 4
#define f2(x, y, z)  (19 - 2 * x + 1 * z) / 7
#define f3(x, y, z)  (31 - 1 * x + 3 * y) / 12

double max2(double a, double b) {
    return (a > b) ? a : b;
}

double max3(double a, double b, double c) {
    return max2(max2(a, b), c);
}

int main() {
    double x0 = 0, y0 = 0, z0 = 0, x1, y1, z1;
    double e1, e2, e3, err_r, e;
    int it = 1;

    printf("Nhap sai so e: ");
    scanf("%lf", &e);

    do {
        x1 = f1(x0, y0, z0);
        y1 = f2(x0, y0, z0); // thay x0 thanh x1 neu gauss_seidel
        z1 = f3(x0, y0, z0); // thay x0, y0 thanh x1, y1 neu gauss_seidel

        printf("Lan lap %d:\t x = %.6lf\t y = %.6lf\t z = %.6lf\n", it, x1, y1, z1);

        e1 = fabs(x1 - x0);
        e2 = fabs(y1 - y0);
        e3 = fabs(z1 - z0);
        err_r = max3(e1, e2, e3);

        x0 = x1;
        y0 = y1;
        z0 = z1;

        it++;
    } while (err_r > e);

    printf("\nNghiem gan dung: x = %.6lf, y = %.6lf, z = %.6lf\n", x1, y1, z1);
    
    return 0;
}

