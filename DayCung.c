#include <stdio.h>
#include <math.h>

double f(double x) {
    return x * x * x - x - 1;
}

int main() {
    double a, b, eps;
    printf("Nhap a, b, eps: ");
    scanf("%lf %lf %lf", &a, &b, &eps);

    double x0 = a, x1 = b, x2;
    int it = 1, max_iter = 100;

    printf("\n%-6s%-15s%-15s%-15s\n", "Lan", "x", "f(x)", "Sai so");

    do {
        double fx0 = f(x0);
        double fx1 = f(x1);

        if (fabs(fx1 - fx0) < 1e-12) {
            printf("Loi: Mau so qua nho (fx1 - fx0 ˜ 0), co the gay chia cho 0!\n");
            return 1;
        }

        x2 = x1 - fx1 * (x1 - x0) / (fx1 - fx0);

        printf("%-6d%-15.6lf%-15.6lf%-15.6lf\n", it, x2, f(x2), fabs(x2 - x1));

        x0 = x1;
        x1 = x2;
        it++;

        if (it > max_iter) {
            printf("Vuot qua so lan lap cho phep (%d lan).\n", max_iter);
            return 1;
        }

    } while (fabs(x1 - x0) >= eps);

    printf("\n=> Gia tri gan dung cua nghiem: %.6lf\n", x2);
    return 0;
}

