// Using the Newton-Raphson method, obtain the formula for √N and find √20 correct to 2 decimal places.Write its computer programme in 'C' language

#include <stdio.h>
#include <math.h>

double sqrt_newton(double N) {
    double x0 = 1.0;
    double x1, fx0, dfx0;
    int max_iter = 1000;
    double tol = 1e-6;

    printf("\nStep\t\tx0\t\tf(x0)\t\tx1\t\tf(x1)\n");
    for (int i = 0; i < max_iter; i++) {
        fx0 = x0*x0 - N;
        dfx0 = 2*x0;

        x1 = (x0 + N/x0)/2;

        if (fabs(x1*x1 - N) < tol) {
            break;
        }
        printf("%d\t\t%f\t%f\t%f\t%f\n",i+1,x0,fx0,x1,dfx0);
        x0 = x1;
    }

    return x1;
}

int main() {
    double N = 20.0;
    double sqrt_N = sqrt_newton(N);

    printf("The square root of %.2lf is: %.2lf\n", N, sqrt_N);

    return 0;
}
