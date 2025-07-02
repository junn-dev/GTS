#include <stdio.h>
#include <math.h>

// f(x) = 0 -> x = g(x)
float g(float x) {
    return -3 * x * x * x + 3 * x * x - 0.36 * x + 0.2465;
}

int main() {
    double x_old, x_new, eps, saiso, k;
    int count = 0, max_iter = 1000;

    printf("Nhap x0, k, epsilon: ");
    scanf("%lf %lf %lf", &x_old, &k, &eps);

    printf("\n%-5s %-15s %-15s %-15s\n", "Iter", "x_n", "x_{n+1}", "Sai so");
    
    do {
        x_new = g(x_old); // x[n + 1] = g(x[n])
        saiso = fabs(x_new - x_old); // |x[n + 1] - x[n]|

        printf("%-5d %-15lf %-15lf %-15lf\n", count, x_old, x_new, saiso);

        x_old = x_new;
        count++;
    } while (saiso > eps * (1 - k) / k && count < max_iter); // |x[n + 1] - x[n]| * k / (1 - k) < e

    printf("\nNghiem gan dung x = %lf\n", x_new);
    printf("So lan lap = %d\n", count);

    return 0;
}

