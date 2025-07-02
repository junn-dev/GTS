#include <stdio.h>
#include <math.h>

//#define f(x) sin(x) / x
#define f(x) (x * x * exp(x)) / (3 * x * x + 8.2)

//float P(float x, float a[], int n) {
//	int i;
//    float tong = 0;
//    for (i = 0; i <= n; i++)
//        tong += a[i] * pow(x, n - i);
//    return tong;
//}

int main() {
    int n, i;
    double a, b;

    printf("Nhap can duoi a, can tren b va so doan n (n chan): ");
    scanf("%lf %lf %d", &a, &b, &n);

    if (n % 2 != 0) {
        printf("Simpson 1/3 yeu cau n phai chan.\n");
        return 1;
    }

    double h = (b - a) / n;
    double s = f(a) + f(b);

    for (i = 1; i < n; i++) {
        double x = a + i * h; // Tính x_i
        if (i % 2 == 0)
            s += 2 * f(x); // * 2 neu i chan
        else
            s += 4 * f(x); // * 4 neu i le
    }

    s *= h / 3; // tong * voi h / 3

    printf("Gia tri tich phan theo cong thuc Simpson 1/3 = %.6lf\n", s);
    
//    int n, i;
//    float a[20], a_val = -3, b_val = 7;
//    int m = 10;
//    float h = (b_val - a_val) / m;
//    float S = 0;
//
//    printf("Nhap bac da thuc: "); scanf("%d", &n);
//    printf("Nhap %d he so a0 -> a%d:\n", n + 1, n);
//    for (i = 0; i <= n; i++) scanf("%f", &a[i]);
//
//    for (i = 0; i <= m; i++) {
//        float x = a_val + i * h;
//        float w = (i == 0 || i == m) ? 1 : (i % 2 == 0 ? 2 : 4);
//        S += w * P(x, a, n);
//    }
//
//    S = S * h / 3;
//    printf("Tich phan ~ %.6f\n", S);

    return 0;
}

//#include <stdio.h>
//
//int main() {
//    double x[] = {1.0, 1.2, 1.4, 1.6, 1.8};
//    double y[] = {1.3, 1.41, 1.53, 1.86};
//    int n = 4;
//    double target = 1.28;
//    double h = (x[n] - x[0]) / n;
//
//    // I = h/3 [y0 + 4y1 + 2y2 + 4y3 + y4]
//    double sum = y[0];
//    int i;
//    for (i = 1; i < n; i++) {
//        int factor = (i % 2 == 0) ? 2 : 4;
//        sum += factor * y[i];
//    }
//
//    double a = (target * 3 / h - sum);
//
//    printf("y(%.2lf) = %.4lf\n", x[n], a);
//
//    return 0;
//}

