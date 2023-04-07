// Find the real root of the equations log x = cos x using Newton-Raphson method. Write its computer programme in 'C' language

/*Regula-Falsi Method
#include <stdio.h>
#include <math.h>

double f(double x) {
    return log(x) - cos(x);
}

int main() {
    double a = 1.0;
    double b = 2.0;
    double c, fc;
    int max_iter = 1000;
    double tol = 1e-6;

    for (int i = 0; i < max_iter; i++) {
        c = (a*f(b) - b*f(a))/(f(b) - f(a));
        fc = f(c);

        if (fabs(fc) < tol) {
            break;
        }

        if (fc > 0) {
            b = c;
        } else {
            a = c;
        }
    }

    printf("The real root of the equation log(x) = cos(x) is: %.6lf\n", c);

    return 0;
}
*/

#include <stdio.h>
#include <math.h>

double f(double x) {
    return log(x) - cos(x);
}

double fprime(double x) {
    return 1/x + sin(x);
}

int main() {
    double x0 = 1.5;
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

    printf("The real root of the equation log(x) = cos(x) is: %.6lf\n", x1);

    return 0;
}
