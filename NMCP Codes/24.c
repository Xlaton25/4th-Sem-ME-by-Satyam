/*
Evaluate the integral √(cosθ) from 0 to π/2 by dividing the  interval into 6 parts.
*/

// #include <stdio.h>
// #include <math.h>
// #define M_PI 3.14159265358979323846

// int main() {
//     float a = 0;
//     float b = M_PI / 2;
//     float h = (b - a) / 6;
//     float sum = 0; 
//     for (int i = 1; i < 6; i++) { // Simpson's rule
//         if (i % 2 == 0) {
//             sum += 2 * sqrt(cos(a + i * h));
//         } else {
//             sum += 4 * sqrt(cos(a + i * h));
//         }
//     }
//     sum = (sqrt(cos(a)) + sum + sqrt(cos(b))) * h / 3;
//     printf("Value of the integral: %f\n", sum);
//     return 0;
// }

#include <stdio.h>
#include <math.h>
#define M_PI 3.14159265358979323846

double f(double theta) {
    return sqrt(cos(theta));
}

int main() {
    double a = 0.0; // lower limit of integration
    double b = M_PI/2; // upper limit of integration
    int n = 6; // number of segments
    double h = (b-a)/n; // width of each segment
    double sum = 0.0; // initialize sum

    // trapezoidal rule integration
    sum += f(a) + f(b);

    for(int i=1; i<n; i++) {
        double x = a + i*h;
        sum += 2*f(x);
    }

    sum *= h/2;

    printf("Approximate value of integral of √cosθ from 0 to π/2: %lf\n", sum);

    return 0;
}
