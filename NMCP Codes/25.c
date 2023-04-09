/*
Evaluate integration of logex from 4 to 5.2 by Simpson's 3/8th rule. Also write its programme in 'C language.
*/

#include <stdio.h>
#include <math.h>

double f(double x) {
    return log(x);
}

int main() {
    double a = 4.0; // lower limit of integration
    double b = 5.2; // upper limit of integration
    int n = 6; // number of segments (n is always a multiple of 6 in Simpson's 3/8th rule)
    double h = (b-a)/n; // width of each segment
    double sum = 0.0; // initialize sum

    // simpson's 3/8th rule integration
    sum += f(a) + f(b);

    for(int i=1; i<n; i++) {
        double x = a + i*h;
        if(i%3 == 0) {
            sum += 2*f(x);
        }
        else {
            sum += 3*f(x);
        }
    }

    sum *= 3*h/8;

    printf("Approximate value of integral of ln(x) from 4 to 5.2: %lf\n", sum);

    return 0;
}
