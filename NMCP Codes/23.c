/*
A solid of revolution is formed by rotating about x-axis, the lines x = O and x = 1 and a curve through the points with the following coordinates.
x : 0, 0.25, 0.5, 0.751
y : 1, 0.9896, 0.9589, 0.9089, 0.8415
Estimate the volume of the solid formed using Simpson's rule.
*/

#include <stdio.h>
#include <math.h>

int main() {
    float x[5] = {0, 0.25, 0.5, 0.75, 1};
    float y[5] = {1, 0.9896, 0.9589, 0.9089, 0.8415};
    float h = 0.25; // 0.25 = 0.75 - 0.5
    float sum = 0;
    for (int i = 1; i < 4; i++) {
        if (i % 2 == 0) {
            sum += 2 * y[i];
        } else {
            sum += 4 * y[i];
        }
    }
    sum = (y[0] + sum + y[4]) * h / 3;
    printf("Volume of the solid formed: %f\n", sum);
    return 0;
}