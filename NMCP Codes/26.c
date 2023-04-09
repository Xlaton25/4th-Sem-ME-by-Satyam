/*
Evaluate integration of logex from 4 to 5.2 by Trapezoidal rule. Also write its programme in 'C language.
*/

#include <stdio.h>
#include <math.h>

double func(double x) {
    return log(x)*exp(x);
}

int main() {
    double a = 4, b = 5.2; // limits of integration
    int n = 10; // number of intervals
    double h = (b-a)/n; // width of each interval

    // trapezoidal rule
    double sum = (func(a) + func(b))/2;

    for(int i=1; i<n; i++) {
        double x = a + i*h;
        sum += func(x);
    }

    double approx = h*sum;
    printf("Approximate value of integral: %lf\n", approx);

    return 0;
}
