// Compute one positive root of 2x — log_10(x) = 7 by the Newton-Raphson method correct to four decimal places. Write its computer programme in 'C' language.


#include <stdio.h>
#include <math.h>

double function(double x) {
    return (2*x - log(x) - 7);
}

double derivative(double x) {
    return (2 + 1/x);
}

int main() {
    double x0, x1, error;
    int i = 0;

    printf("Enter an initial guess: ");
    scanf("%lf", &x0);

    do {
        x1 = x0 - function(x0)/derivative(x0);
        error = fabs((x1 - x0)/x1);
        x0 = x1;
        i++;
    } while (error > 0.0001 && i < 100); // stop after 100 iterations or when the error is less than 0.0001

    printf("The positive root is approximately %.4lf\n", x1);
    
    return 0;
}
