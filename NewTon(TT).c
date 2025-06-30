#include <stdio.h>
#include <math.h>

float f(float x) {
    return pow(x, 3) - 3 * x + 1;
}

float df(float x) {
    return 3 * pow(x, 2) - 3;
}

int main() {
    float x0, e, x1;
    int n = 0, MAX = 1000;

    printf("Nhap x0, sai so e: ");
    scanf("%f %f", &x0, &e);

    while (1) {
        float dfx = df(x0);
        if (dfx == 0) {
            printf("Dao ham bang 0, phuong phap that bai.\n");
            return 1;
        }

        x1 = x0 - f(x0)/dfx;
        n++;

        if (fabs(x1 - x0) < e || n >= MAX) break;
        x0 = x1;
    }

    if (n >= MAX)
        printf("Khong hoi tu sau %d buoc lap.\n", MAX);
    else
        printf("Gia tri gan dung la %.4f sau %d buoc lap\n", x1, n);

    return 0;
}

