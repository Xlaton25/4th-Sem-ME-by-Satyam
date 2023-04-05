//Find the root of the equation x^e = cos x in the interval (0, 1) using Regular-Falsi method correct to four decimal places. Write its computer programme in 'C' language.

#include <stdio.h>
#include <math.h>

#define MAX_ITER 100 // Maximum number of iterations
#define EPSILON 0.0001 // Error tolerance

double f(double x, double e) {
    return pow(x,e) - cos(x);
}

int main() {
    double a = 0, b = 1, c, fa, fb, fc;
    int iter = 0;

    do {
        fa = f(a,1.5);
        fb = f(b,1.5);

        c = a - ((fa*(b-a))/(fb-fa));
        fc = f(c,1.5);

        if (fa * fc < 0) {
            b = c;
        } else {
            a = c;
        }

        iter++;
    } while (fabs(fc) > EPSILON && iter < MAX_ITER);

    if (iter == MAX_ITER) {
        printf("Failed to find root within %d iterations\n", MAX_ITER);
    } else {
        printf("Root: %.4f\n", c);
    }

    return 0;
}


/*
1. Initialize variables a and b as 0 and 1 respectively.
2. Compute f(a) = a^e - cos(a) and f(b) = b^e - cos(b).
3. Repeat the following steps until the root is found or the maximum number of iterations is reached:
        Compute the value of c using the formula: c = a - ((f(a)*(b-a))/(f(b)-f(a)))
        Compute f(c) = c^e - cos(c)
        If f(c) is very close to zero, then c is the root of the equation. Exit the loop and return the value of c.
        If f(c) has the same sign as f(a), then set a = c, else set b = c.
        If the maximum number of iterations is reached and a root has not been found, then print an error message.
*/