/*
Find integration of (e^x/(1+x)) from 0 to 6 approximately using Simpson's 3/8th rule on integration. lso write its programme in 'C language.

*/

// #include <stdio.h>
// #include <math.h>

// int main() {
//     float x[7] = {0, 1, 2, 3, 4, 5, 6};
//     float fx[7] = {1, 0.5, 0.333333, 0.25, 0.2, 0.166667, 0.142857};
//     float h = 1; // 1 = 1 - 0
//     float sum = 0;
//     for (int i = 1; i < 6; i++) {
//         if (i % 3 == 0) {
//             sum += 2 * fx[i];
//         } else {
//             sum += 3 * fx[i];
//         }
//     }
//     sum = (fx[0] + sum + fx[6]) * 3 * h / 8;
//     printf("Integration of f(x) from 0 to 6: %f\n", sum);
//     return 0;
// }

#include <stdio.h>
#include <math.h>

double func(double x) {
    return exp(x)/(1+x);
}

int main() {
    double a = 0, b = 6;
    int n = 6; // number of intervals (must be a multiple of 3)
    double h = (b-a)/n;

    // simpson's 3/8th rule
    double sum = func(a) + func(b);

    for(int i=1; i<n; i++) {
        double x = a + i*h;
        if(i%3==0) sum += 2*func(x);
        else sum += 3*func(x);
    }

    // double approx = 3*h*sum/8;
    sum *= 3*h/8;
    printf("Approximate value of integral: %lf\n", sum);

    return 0;
}
