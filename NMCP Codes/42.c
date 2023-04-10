#include <stdio.h>
#include <math.h>


int main() {
    double x[10] = {1,2,3,4,5,6,7,8,9,10};
    double y[10] = {52.5,58.7,65,70.2,75.4,81.1,87.2,95.5,102.2,108.4};
    double sum_x = 0.0, sum_y = 0.0, sum_xy = 0.0, sum_x2 = 0.0;
    double a, b, r2;
    int i;

    for (i = 0; i < 6; i++) {
        sum_x += x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
        sum_x2 += x[i] * x[i];
    }

    b = (10 * sum_xy - sum_x * sum_y) / (10 * sum_x2 - sum_x * sum_x);
    a = (sum_y - b * sum_x) / 10;

    printf("Equation: y = %g + %g * x\n", a, b);
    // printf("R-squared: %g\n", r2);

    return 0;
}
