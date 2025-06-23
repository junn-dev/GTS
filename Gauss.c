#include <stdio.h>
#include <math.h>

#define f1(x, y, z, t)  6 - 2 * y - 3 * x + 2 * t
#define f2(x, y, z, t)  -8 + 2 * x - 2 * z - 3 * t
#define f3(x, y, z, t)  -4 + 3 * x + 2 * y + 2 * t
#define f4(x, y, z, t)  -8 - 2 * x + 3 * y - 2 * z

double max(double a, double b, double c, double d) {
    double m = a;
    if (b > m) m = b;
    if (c > m) m = c;
    if (d > m) m = d;
    return m;
}

int main() {
    double x0 = 0, y0 = 0, z0 = 0, t0 = 0, x1, y1, z1, t1;
    double e1, e2, e3, e4, err_r, e;
    int it = 1, max_it = 100;

    printf("Nhap sai so e: ");
    scanf("%lf", &e);

    printf("\n%-6s%-12s%-12s%-12s%-12s%-12s\n", "Lan", "x", "y", "z", "t", "Sai so");

    do {
        x1 = f1(x0, y0, z0, t0);
        y1 = f2(x1, y0, z0, t0);
        z1 = f3(x1, y1, z0, t0);
        t1 = f4(x1, y1, z1, t0);

        e1 = fabs(x1 - x0);
        e2 = fabs(y1 - y0);
        e3 = fabs(z1 - z0);
        e4 = fabs(t1 - t0);
        err_r = max(e1, e2, e3, e4);

        printf("%-6d%-12.6lf%-12.6lf%-12.6lf%-12.6lf%-12.6lf\n", it, x1, y1, z1, t1, err_r);

        x0 = x1;
        y0 = y1;
        z0 = z1;
        t0 = t1;

        it++;
        if (it > max_it) {
            printf("Vuot qua so lan lap cho phep (%d).\n", max_it);
            break;
        }

    } while (err_r > e);

    printf("\n=> Nghiem gan dung:\n x = %.6lf\n y = %.6lf\n z = %.6lf\n t = %.6lf\n", x1, y1, z1, t1);

    return 0;
}

