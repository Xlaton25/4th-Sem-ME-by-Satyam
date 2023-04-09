/*
Find, from the following table, the area bounded by the curve and the x-axis from x = 7.47 to x = 7.52.
x : 7.47, 7.48, 7.49, 7.50, 7.51, 7.52
f(x) : 1.93, 1.95, 1.98, 2.01, 2.03, 2.06
*/
#include <stdio.h>
#include <math.h>

int main() {
    float x[6] = {7.47, 7.48, 7.49, 7.50, 7.51, 7.52};
    float fx[6] = {1.93, 1.95, 1.98, 2.01, 2.03, 2.06};
    float h = 0.01; // 0.01 = 7.52 - 7.51
    float sum = 0;
    for (int i = 1; i < 5; i++) {
        if (i % 2 == 0) {
            sum += 2 * fx[i];
        } else {
            sum += 4 * fx[i];
        }
    }
    sum = (fx[0] + sum + fx[5]) * h / 3;
    printf("Integration of f(x) from 7.47 to 7.52: %f\n", sum);
    return 0;
}