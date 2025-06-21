#include <stdio.h>
#include <math.h>

double f(double x){
    return sqrt(x) + sin(x) - 10;
}

int main() {
    double a, b, eps;
    printf("Nhap a, b, eps: ");
    scanf("%lf %lf %lf", &a, &b, &eps);

    double x0 = a, x1 = b, x2;
    int it = 1, max_iter = 100;

    do {
        double fx0 = f(x0), fx1 = f(x1);
        
        if (fabs(fx1 - fx0) < 1e-12) {
            printf("Mau so qua nho, co the gay chia cho 0!\n");
            return 1;
        }

        x2 = x1 - fx1 * (x1 - x0) / (fx1 - fx0); 
        printf("Lan %d:\t x = %.6lf\t f(x) = %.6lf\t sai so: %.6lf\n", it, x2, f(x2), fabs(x2 - x1));

        x0 = x1;
        x1 = x2;
        it++;

        if (it > max_iter) {
            printf("Vuot qua so lan lap cho phep.\n");
            break;
        }
    } while (fabs(f(x2)) > eps);

    printf("\nGia tri gan dung cua nghiem: %.6lf\n", x2);

    return 0;
}

