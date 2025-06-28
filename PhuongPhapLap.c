#include <stdio.h>
#include <math.h>

float g(float x) {
    return -3 * x * x * x + 3 * x * x - 0.36 * x + 0.2465;
}

int main() {
    double x_old, x_new, eps, delta;
    int count = 0, max_iter = 1000;

    printf("Nhap x0, epsilon: ");
    scanf("%lf %lf", &x_old, &eps);

    printf("\n%-5s %-15s %-15s %-15s\n", "Iter", "x_n", "x_{n+1}", "Sai so");
    
    do {
        x_new = g(x_old);
        delta = fabs(x_new - x_old);

        printf("%-5d %-15.10f %-15.10f %-15.10f\n", count, x_old, x_new, delta);

        x_old = x_new;
        count++;
    } while (delta > eps && count < max_iter);

    printf("\nNghiem gan dung x = %.10f\n", x_new);
    printf("So lan lap = %d\n", count);

    return 0;
}
