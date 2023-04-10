#include <stdio.h>
#include <math.h>


int main() {
    double x[4] = {12,15,21,25};
    double y[4] = {50,70,100,120};
    double sum_x = 0.0, sum_y = 0.0, sum_xy = 0.0, sum_x2 = 0.0;
    double a, b, r2;
    int i;

    for (i = 0; i < 4; i++) {
        sum_x += x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
        sum_x2 += x[i] * x[i];
    }

    b = (4 * sum_xy - sum_x * sum_y) / (4 * sum_x2 - sum_x * sum_x);
    a = (sum_y - b * sum_x) / 4;

    printf("Equation: y = %g + %g * x\n", a, b);
    // printf("R-squared: %g\n", r2);S
    return 0;
}
