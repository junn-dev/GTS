#include <stdio.h>
#include <math.h>

#define MAX 100

// Hàm f(x) = 2^x / (x^2 + 1)
float fx(float x) {
    return pow(2, x) / (x * x + 1);
}

// T?o b?ng sai phân ti?n
void tao_bang_sai_phan(float f[][MAX], int n) {
    int i, j;
    for (j = 1; j < n; j++) {
        for (i = 0; i < n - j; i++) {
            f[i][j] = f[i + 1][j - 1] - f[i][j - 1];
        }
    }
}

// Tính giai th?a
int giaithua(int n) {
    if (n <= 1) return 1;
    return n * giaithua(n - 1);
}

// N?i suy Newton ti?n
float noi_suy_newton(float x[], float f[][MAX], int n, float xp) {
    float h = x[1] - x[0];
    float p = (xp - x[0]) / h;

    float kq = f[0][0];
    float p_tich = 1.0;
    int i;

    for (i = 1; i < n; i++) {
        p_tich *= (p - (i - 1));
        kq += (p_tich * f[0][i]) / giaithua(i);
    }

    return kq;
}

int main() {
    int n, i;
    float x[MAX], f[MAX][MAX], xp, ketqua;

    printf("Nhap so diem n: ");
    scanf("%d", &n);

    printf("Nhap cac moc x (deu cach):\n");
    for (i = 0; i < n; i++) {
        printf("x[%d] = ", i);
        scanf("%f", &x[i]);
        f[i][0] = fx(x[i]); 
    }

    tao_bang_sai_phan(f, n);

    printf("Nhap x can noi suy: ");
    scanf("%f", &xp);

    ketqua = noi_suy_newton(x, f, n, xp);
    printf("f(%.4f) ~= %.6f\n", xp, ketqua);

    return 0;
}

