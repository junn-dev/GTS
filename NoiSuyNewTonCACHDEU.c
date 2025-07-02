#include <stdio.h>
#include <math.h>

#define MAX 100

double fx(double x) {
    return pow(2, x) / (x * x + 1); 
}

int giaithua(int n) {
    if (n <= 1) return 1;
    return n * giaithua(n - 1);
}

int main() {
    int n, i, j;
    double x[MAX], y[MAX], f[MAX][MAX], xp, h, p, ketqua, p_tich;

    printf("Nhap so diem n: ");
    scanf("%d", &n);


    for (i = 0; i < n; i++) {
        printf("x[%d] = ", i);
        scanf("%lf", &x[i]);
        
        // Neu nhap y(x) theo bang
        printf("y[%d] = ", i);
        scanf("%lf", &y[i]);
        
        // Neu tinh theo f(x)
//        y[i] = fx(x[i]);
//        printf("y[%d] = f(%.2lf) = %.6lf\n", i, x[i], y[i]);

        f[i][0] = y[i];
    }

    // B1: Tinh khoang cach deu giua cac diem moc
    h = x[1] - x[0];

    // B2: Kiem tra tat ca cac khoang co cach deu nhau khong
    for (i = 1; i < n - 1; i++) {
        if (fabs((x[i+1] - x[i]) - h) > 1e-6) {
            printf("Loi: x khong cach deu!\n");
            return 1; // Thoat neu khong deu
        }
    }

    // B3: Tinh bang sai phan tien f[i][j]
    // f[i][j] = delta^j(f(x_i)) = f[i+1][j-1] - f[i][j-1]
    for (j = 1; j < n; j++) {
        for (i = 0; i < n - j; i++) {
            f[i][j] = f[i + 1][j - 1] - f[i][j - 1];
        }
    }

    // B4: In bang sai phan tien
    printf("\nBang sai phan tien:\n");
    for (i = 0; i < n; i++) {
        printf("x = %.2lf\t", x[i]);
        for (j = 0; j < n - i; j++) {
            printf("%.6lf\t", f[i][j]);
        }
        printf("\n");
    }

    // B5: Nhap gia tri can noi suy
    printf("\nNhap gia tri x can noi suy: ");
    scanf("%lf", &xp);

    // B6: Tinh p theo cong thuc p = (x - x0) / h
    p = (xp - x[0]) / h;

    // B7: Ap dung cong thuc
    // f(x) ~ f(x0) + p * delta(f(x0)) + p * (p - 1) / 2! delta^2(f(x0)) + ... + p * (p - 1) * ... *(p - n + 1) / n! delta^n(f(x0))
    ketqua = f[0][0];    // Term d?u tiên: f(x0)
    p_tich = 1.0;        // p(p - 1)...(p - k + 1) (tích lu? t?ng b?c)

    for (i = 1; i < n; i++) {
        p_tich *= (p - (i - 1));                          // Cap nhat p * (p - 1) * ... * (p - i + 1)
        ketqua += (p_tich * f[0][i]) / giaithua(i);       // Cong vao ket qua: (p_tich * delta^i(f(x0))) / i!
    }


    printf("\n=> Gia tri noi suy tai x = %.6lf la y = %.6lf\n", xp, ketqua);

    return 0;
}

