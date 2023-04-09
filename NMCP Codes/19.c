/*
Use Trapezoidal rule to evaluate integration of x^3 from 0 to 1 considering five sub-intervals.
Write its computer programme in 'C' language

*/

// #include <stdio.h>
// #include <math.h>

// int main() {
//     float a = 0, b = 1;
//     int n = 5;
//     float h = (b - a) / n;
//     float sum = 0;
//     for (int i = 1; i < n; i++) {
//         sum += pow(a + i*h, 3);
//     }
//     sum = (pow(a, 3) + 2*sum + pow(b, 3)) * h / 2;
//     printf("Integration of x^3 from 0 to 1: %f\n", sum);
//     return 0;
// }

/*
#include <stdio.h>
#include <math.h>

// Define function to integrate
float f(float x) {
    return pow(x, 3);
}

int main() {
    int n = 5; // Number of sub-intervals
    float a = 0.0, b = 1.0; // Integration limits
    float h = (b - a) / n;
    float sum = 0.0;

    // Trapezoidal rule integration
    for(int i=1; i<n; i++) {
        float x = a + i * h;
        sum += f(x);
    }
    sum += (f(a) + f(b)) / 2.0;
    sum *= h;

    printf("Result of integration using Trapezoidal rule: %.5f\n", sum);

    return 0;
}
*/

#include <stdio.h>
#include <math.h>

/* Define function here */
#define f(x) pow(x, 3)

int main()
{
    float lower, upper, integration = 0.0, stepSize, k;
    int i, subInterval;
    /* Input */
    printf("Enter lower limit of integration: ");
    scanf("%f", &lower);
    printf("Enter upper limit of integration: ");
    scanf("%f", &upper);
    printf("Enter number of sub intervals: ");
    scanf("%d", &subInterval);

    /* Calculation */
    /* Finding step size */
    stepSize = (upper - lower) / subInterval;

    /* Finding Integration Value */
    integration = f(lower) + f(upper);
    for (i = 1; i <= subInterval - 1; i++)
    {
        k = lower + i * stepSize;
        integration = integration + 2 * f(k);
    }
    integration = integration * stepSize / 2;
    printf("\nRequired value of integration is: %.4f", integration);
    return 0;
}