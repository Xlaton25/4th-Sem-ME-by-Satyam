/*
Using Newton's formula for interpolation, estimate the population for the year 1905
from the table:
Year
1891
1901
1911
1921
1931

Population
98,752
132,285
168,076
195,690
246,050
Write its computer programme in 'C' language
*/

#include <stdio.h>
#include <math.h>

int main() {
    double x[] = {1891, 1901, 1911, 1921, 1931};
    double y[] = {98752, 132285, 168076, 195690, 246050};
    double u = (1905 - x[0]) / (x[1] - x[0]);
    double dy[5][5];
    int i, j;

    for (i = 0; i < 5; i++) {
        dy[i][0] = y[i];
    }

    for (j = 1; j < 5; j++) {
        for (i = 0; i < 5 - j; i++) {
            dy[i][j] = dy[i+1][j-1] - dy[i][j-1];
        }
    }

    printf("Difference Table:\n\n");
    for (i = 0; i < 5; i++) {
        printf("%.0f\t", x[i]);
        for (j = 0; j < 5 - i; j++) {
            printf("%.4f\t", dy[i][j]);
        }
        printf("\n");
    }

    double sum = dy[0][0];
    double prod = 1;
    for (j = 1; j < 5; j++) {
        prod *= (u-j+1) / j;
        sum += prod * dy[0][j];
    }

    printf("\nEstimated population for 1905: %f\n", sum);
    return 0;
}
