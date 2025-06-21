#include <stdio.h>

typedef struct {
    double x;
    double y;
} Point;

int main() {
//    Point p[] = {
//        {1.0, 2.0},
//        {2.0, 4.0},
//        {3.0, 6.0},
//        {4.0, 8.0}
//    };
//
//    int n = sizeof(p) / sizeof(p[0]);
    
    Point p[100];
    int n;
    printf("Nhap so luong gia tri cho truoc: ");
    scanf("%d", &n);
    
    int i, j;
    for (i = 0; i < n; i++) {
    	printf("(x%d, y%d) = ", i + 1, i + 1);
    	scanf("%lf %lf", &p[i].x, &p[i].y);
	}

    double x;
    printf("Nhap gia tri x can noi suy: ");
    scanf("%lf", &x);

    double result = 0.0;

    for (i = 0; i < n; i++) {
        double term = p[i].y;
        for (j = 0; j < n; j++) {
            if (j != i) {
                term *= (x - p[j].x) / (p[i].x - p[j].x);
            }
        }
        result += term;
    }
    
    printf("Gia tri noi suy tai x = %.2lf la y = %.6lf\n", x, result);

    return 0;
}

