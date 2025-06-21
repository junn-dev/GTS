#include <stdio.h>
#include <math.h>

#define N 3

int main() {
    double A[N][N] = {
        {4, 1, -1},
        {2, 7, 1},
        {1, -3, 12}
    };
    double b[N] = {3, 19, 31};
    double x[N] = {0, 0, 0};

//    double A[N][N], b[N], x[N];
//    
    int i, j;
//
//    for (i = 0; i < N; i++) {
//        for (j = 0; j < N; j++) {
//            printf("A[%d][%d] = ", i + 1, j + 1);
//            scanf("%lf", &A[i][j]);
//        }
//    }
//
//    for (i = 0; i < N; i++) {
//        printf("b[%d] = ", i + 1);
//        scanf("%lf", &b[i]);
//    }
//
//    for (i = 0; i < N; i++) {
//        x[i] = 0;
//    }

    double eps;
    printf("Nhap epsilon (sai so): ");
    scanf("%lf", &eps);

    double xNew[N];
    int it = 0, max_iter = 100;
    double err = eps + 1;

    while (err > eps && it < max_iter) {
        for (i = 0; i < N; ++i) {
            xNew[i] = b[i];
            for (j = 0; j < N; ++j) {
                if (j != i) {
                    xNew[i] -= A[i][j] * x[j];
                }
            }
            xNew[i] /= A[i][i];
        }

        err = 0.0;
        for (i = 0; i < N; ++i) {
            err += fabs(xNew[i] - x[i]);
            x[i] = xNew[i];
        }

        it++;
        
        printf("Lan lap %d:\t", it);
        for (i = 0; i < N; i++)
            printf("x[%d] = %.6lf\t", i + 1, xNew[i]);
        printf("\n");

    }

    printf("\nNghiem gan dung sau %d lan lap:\n", it);
    for (i = 0; i < N; ++i) {
        printf("x[%d] = %.6lf\n", i + 1, x[i]);
    }

    return 0;
}
