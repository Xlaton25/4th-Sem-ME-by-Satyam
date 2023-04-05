// Find the real root of the equation 3x = cos x + 1 by Regula-Falsi method. Write its computer programme in 'C' language.

#include <stdio.h>
#include <math.h>

// Function to calculate f(x) for given x
double func(double x)
{
    return 3 * x - cos(x) - 1;
}

// Regula Falsi Method function
void regulaFalsi(double a, double b)
{
    if (func(a) * func(b) >= 0) {
        printf("Incorrect a and b\n");
        return;
    }

    double c = a;  // Initialize result
    int i;

    for (i = 0; i < 10000; i++) {
        // Find the point that connects x axis with f(a) and f(b)
        c = (a * func(b) - b * func(a)) / (func(b) - func(a));

        // Check if the found point is the root
        if (fabs(func(c)) < 0.0001 || fabs(b-a) < 0.0001)
            break;

        // Decide the side to repeat the steps
        else if (func(c) * func(a) < 0)
            b = c;
        else
            a = c;
    }
    printf("The real root of the equation is: %.4f\n", c);
    printf("The solution was obtained after %d iterations.", i);
}

// Main function
int main()
{
    double a = -1, b = 1;
    regulaFalsi(a, b);
    return 0;
}