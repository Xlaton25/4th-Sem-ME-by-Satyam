/*
Find integration of (e^x/(1+x)) from 0 to 6 approximately using Simpson's 3/8th rule on integration.

*/

#include <stdio.h>
#include <math.h>

int main() {
    float x[7] = {0, 1, 2, 3, 4, 5, 6};
    float fx[7] = {1, 0.5, 0.333333, 0.25, 0.2, 0.166667, 0.142857};
    float h = 1; // 1 = 1 - 0
    float sum = 0;
    for (int i = 1; i < 6; i++) {
        if (i % 3 == 0) {
            sum += 2 * fx[i];
        } else {
            sum += 3 * fx[i];
        }
    }
    sum = (fx[0] + sum + fx[6]) * 3 * h / 8;
    printf("Integration of f(x) from 0 to 6: %f\n", sum);
    return 0;
}