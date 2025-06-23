#include <stdio.h>
#include <math.h>

float g(float x) {
    return sqrt(2 * x + 5);
}

int main() {
    double x_old, x_new, eps;
    printf("Nhap x0, epsilon: ");
    scanf("%lf %lf", &x_old, &eps);

    double delta;
    int count = 0, max_iter = 1000;

    do {
        x_new = g(x_old);
        delta = fabs(x_new - x_old);
        printf("%-10d %-15.6f %-15.6f %-15.6f\n", count, x_old, x_new, delta);
        x_old = x_new;
        count++;
    } while (delta > eps && count < max_iter);

    printf("x = %.6f\n", x_new);
    printf("So lan lap = %d\n", count);
}

