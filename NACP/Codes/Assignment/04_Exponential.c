/*****************************************************************************
C program to calculate the value of the exponential e^1 up to 5 decimal points
******************************************************************************/

#include <stdio.h>

double calculate_exponential(); 

int main() {
    double result;

    result = calculate_exponential();
    printf("The value of e^1 up to 5 decimal points is: %.5f\n", result);

    return 0;
}

double calculate_exponential() {
    int i, j, factorial;
    double x, e_to_x;

    x = 1.0;
    e_to_x = 1.0;

    for (i = 1; i <= 15; i++) {
        factorial = 1;
        for (j = 1; j <= i; j++) {
            factorial *= j;
        }
        e_to_x += x / factorial;
        x *= 1.0;
    }

    return e_to_x;
}
/*****************************************************************************
1. The calculate_exponential() function calculates the value of e^1 up to 15 terms of the infinite series expansion of the exponential function, using the formula:

e^x = 1 + x/1! + x^2/2! + x^3/3! + ...

In this case, x is set to 1.0 (to calculate e^1).

2. The function uses nested loops to calculate the factorials of the numbers 1 through 15 and to add up the terms of the infinite series.

3. The value of e^1 up to 15 terms is returned by the function.

4. In the main() function, the calculate_exponential() function is called and its result is printed with 5 decimal points using the %f format specifier with the precision .5.

*********************************************************************************/