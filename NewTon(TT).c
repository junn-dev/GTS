#include <stdio.h>
#include <math.h>

// f(x)
double f(double x) {
    return 3 * pow(x, 5) + 6 * x - 10;
}

// f'(x)
double df(double x) {
    return 15 * pow(x, 4) + 6;
}

int main() {
    double x_old, x_new, eps;
    int count = 0, max_iter = 1000;

    printf("Nhap x0, sai so epsilon: ");
    scanf("%lf %lf", &x_old, &eps);

    printf("\n%-5s %-15s %-15s %-15s %-15s\n", "Iter", "x_n", "f(x_n)", "f'(x_n)", "|x_{n+1}-x_n|");

    double delta;

    do {
        double fx = f(x_old);
        double dfx = df(x_old);

        x_new = x_old - (fx / dfx); // x[n + 1] = x[n] - f(x[n]) / f'(x[n])
        delta = fabs(x_new - x_old); // |x[n + 1] - x[n]|

        printf("%-5d %-15.10f %-15.10f %-15.10f %-15.10f\n", count, x_old, fx, dfx, delta);

        x_old = x_new;
        count++;

    } while (delta > eps && count < max_iter);

    printf("\nNghiem gan dung x = %.10f\n", x_new);
    printf("So lan lap = %d\n", count);

    return 0;
}

