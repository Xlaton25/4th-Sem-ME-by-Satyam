/*
The speed, v meters per second, of a car, t seconds after it starts, is shown in the following table:
t : 0, 12, 24, 36, 48, 60, 72, 84, 96, 108, 120
v: 0, 3.60, 10.08, 18.90, 21.60, 18.54, 10.26, 5.40, 4.50, 5.40, 9.00
Using Simpson's rule, find the distance travelled by the car in 2 minutes.
Write its computer programme in 'C' language
*/

#include <stdio.h>
#include <math.h>

int main() {
    float t[11] = {0, 12, 24, 36, 48, 60, 72, 84, 96, 108, 120};
    float v[11] = {0, 3.60, 10.08, 18.90, 21.60, 18.54, 10.26, 5.40, 4.50, 5.40, 9.00};
    float h = 12;
    float sum = 0;
    for (int i = 1; i < 10; i++) {
        if (i % 2 == 0) {
            sum += 2 * v[i];
        } else {
            sum += 4 * v[i];
        }
    }
    sum = (v[0] + sum + v[10]) * h / 3;
    printf("Integration of v from 0 to 120: %f\n", sum);
    return 0;
}