//Find real cube root of 18 by Regula-Falsi method.

#include <stdio.h>
#include <math.h>

// Function to calculate f(x) for given x
double func(double x)
{
    return x * x * x - 18;
}

// Regula Falsi Method function
void regulaFalsi(double a, double b)
{
    if (func(a) * func(b) >= 0) {
        printf("Incorrect a and b\n");
        return;
    }

    double c = a;  // Initialize result

    for (int i = 0; i < 10000; i++) {
        // Find the point that connects x axis with f(a) and f(b)
        c = (a * func(b) - b * func(a)) / (func(b) - func(a));

        // Check if the found point is the root
        if (func(c) == 0.0 || fabs(b-a) < 0.0001)
            break;

        // Decide the side to repeat the steps
        else if (func(c) * func(a) < 0)
            b = c;
        else
            a = c;
    }
    printf("The real cube root of 18 is: %.6f", c);
}

// Main function
int main()
{
    double a = 1, b = 3;
    regulaFalsi(a, b);
    return 0;
}
