// Find the real root of the equations x^2 + 4 * sin x = 0 using Newton-Raphson method. Write its computer programme in 'C' language

#include <stdio.h>
#include <math.h>

double f(double x) {
    return x*x + 4*sin(x);
}

double fprime(double x) {
    return 2*x + 4*cos(x);
}

int main() {
    double x0 = 2;
    double x1, fx0, fx1, dfx0;
    int max_iter = 1000;
    double tol = 1e-6;

    for (int i = 0; i < max_iter; i++) {
        fx0 = f(x0);
        dfx0 = fprime(x0);

        x1 = x0 - fx0/dfx0;
        fx1 = f(x1);

        if (fabs(x1 - x0) < tol || fabs(fx1) < tol) {
            break;
        }

        x0 = x1;
    }

    printf("The real root of the equation x^2 + 4*sin(x) = 0 is: %.6lf\n", x1);

    return 0;
}
