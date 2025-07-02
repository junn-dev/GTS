#include <stdio.h>
#include <math.h>

//#define f(x) x * pow(M_E, -x)
#define f(x) (5 * x + 4) / (6 * x * x + 9)

int main() {
    int n;
    double a, b;

    printf("Nhap can duoi a, can tren b va so doan n: ");
    scanf("%lf %lf %d", &a, &b, &n);

    double h = (b - a) / n;
    double s = f(a) + f(b);

    int i;
    for (i = 1; i < n; i++) {
        double x = a + i * h; // Tính x_i
        s += 2 * f(x); // Cong 2*f(x_i) vao tong
    }


    // Tích phân ~ (h / 2) * (f(a) + 2for(f(x_i)) + f(b))
    s = (h / 2) * s;


    printf("Gia tri tich phan theo cong thuc hinh thang = %.6lf\n", s);

    return 0;
}

//#include <stdio.h>
//
//int main() {
//    
//    double x[] = {1.11, 1.29, 1.47, 1.65, 1.83, 2.01, 2.19};
//    double y[] = {1.28, 1.66, 2.41, 1.76, 2.63, 3.28}; // thieu A
//    int n = 6;
//    double h = 0.18;
//    double target = 4.2;
//
//    double sum = x[0] * y[0];
//	int i; 
//    for (i = 1; i < n; i++) {
//        sum += 2 * x[i] * y[i];
//    }
//
//    double A = (4.2 * 2 / h - sum) / x[6];
//
//    printf("Gia tri A = f(%.2lf) can tim la: %.10lf\n", x[6], A);
//    return 0;
//}
//

