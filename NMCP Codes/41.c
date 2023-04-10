#include <stdio.h>
#include <math.h>


int main() {
    double x[6] = {100,120,140,160,180,200};
    double y[6] = {0.45,0.55,0.60,0.70,0.80,0.85};
    double sum_x = 0.0, sum_y = 0.0, sum_xy = 0.0, sum_x2 = 0.0;
    double a, b, r2;
    int i;

    for (i = 0; i < 6; i++) { 
        sum_x += x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
        sum_x2 += x[i] * x[i];
    }

    b = (6 * sum_xy - sum_x * sum_y) / (6 * sum_x2 - sum_x * sum_x);
    a = (sum_y - b * sum_x) / 6;

    printf("Equation: y = %g + %g * x\n", a, b);
    // printf("R-squared: %g\n", r2); 

    return 0;
}
