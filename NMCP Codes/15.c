/*Given that
x : 1, 2, 3, 4, 5, 6
y: 0, 1, 8, 27, 64, 125
Use Newton's forward formula to find the value of f(2.5).

Write its computer programme in 'C' language*/

#include <stdio.h>
#include <math.h>

int main() {
    double x[] = {1, 2, 3, 4, 5, 6};
    double y[] = {0, 1, 8, 27, 64, 125};
    double u = (2.5 - x[0]) / (x[1] - x[0]);
    double dy[6][6];
    int i, j;

    for (i = 0; i < 6; i++) {
        dy[i][0] = y[i];
    }

    for (j = 1; j < 6; j++) {
        for (i = 0; i < 6 - j; i++) {
            dy[i][j] = dy[i+1][j-1] - dy[i][j-1];
        }
    }

    printf("Difference Table:\n\n");
    for (i = 0; i < 6; i++) {
        printf("%.0f\t", x[i]);
        for (j = 0; j < 6 - i; j++) {
            printf("%.4f\t", dy[i][j]);
        }
        printf("\n");
    }

    double sum = dy[0][0];
    double prod = 1;
    for (j = 1; j < 4; j++) {
        prod *= (u-j+1) / j;
        sum += prod * dy[0][j];
    }

    printf("\nf(2.5) = %f\n", sum);
    return 0;
}

