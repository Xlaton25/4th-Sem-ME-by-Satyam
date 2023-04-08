/*
Find the number of men getting wages between $ 10 and $ 15 from the following table:
Wages (in $):10—20, 10-20, 20-30, 30-40
Frequency: 9, 30, 35, 42
Use Newton's forward formula to find.

Write its computer programme in 'C' language

*/

#include <stdio.h>
#include <math.h>

int main() {
    double x[] = {10, 20, 30, 40};
    double y[] = {9, 39, 74, 116};
    double u = (15 - x[0]) / (x[1] - x[0]);
    double dy[4][4];
    int i, j;

    for (i = 0; i < 4; i++) {
        dy[i][0] = y[i];
    }

    for (j = 1; j < 4; j++) {
        for (i = 0; i < 4 - j; i++) {
            dy[i][j] = dy[i+1][j-1] - dy[i][j-1];
        }
    }

    printf("Difference Table:\n\n");
    for (i = 0; i < 4; i++) {
        printf("%.0f\t", x[i]);
        for (j = 0; j < 4 - i; j++) {
            printf("%.4f\t", dy[i][j]);
        }
        printf("\n");
    }

    double sum = dy[0][0];
    double prod = 1;
    for (j = 1; j < 3; j++) {
        prod *= (u-j+1) / j;
        sum += prod * dy[0][j];
    }

    printf("\nf(15) = %d\n", (int) round(sum)-(int)y[0]);
    return 0;
}