/*
A curve is drawn to pass through the points given by the following table:
x : 1, 1.5 , 2, 2.5, 3, 3.5, 4
y : 2, 2.4, 2.7, 2.8, 3, 2.6, 2.1

Find
(i) Center of gravity of the area.
(ii) Volume of the solid of revolution.
(iii) The area bounded by the curve, the x-axis and lines x = 1, x = 4.
*/

#include <stdio.h>
#include <math.h>
#define M_PI 3.14159265358979323846

int main()
{
    int n = 7;                                   // Number of intervals
    float x[] = {1, 1.5, 2, 2.5, 3, 3.5, 4};     // Given values of x
    float y[] = {2, 2.4, 2.7, 2.8, 3, 2.6, 2.1}; // Given values of y

    float h = (x[n - 1] - x[0]) / (n - 1); // Calculate interval h
    float odd_sum = 0, even_sum = 0;

    for (int i = 1; i < n - 1; i += 2)
    {
        odd_sum += y[i];
    }

    for (int i = 2; i < n - 2; i += 2)
    {
        even_sum += y[i];
    }

    float area = (h / 3) * (y[0] + 4 * odd_sum + 2 * even_sum + y[n - 1]); // Simpson's 1/3 rule

    float CG_x = ((1.0 / 3) * ((x[0] + x[n - 1]) + 4 * odd_sum + 2 * even_sum)) / area; // Center of gravity in x direction
    float CG_y = ((1.0 / 3) * ((y[0] + y[n - 1]) + 4 * odd_sum + 2 * even_sum)) / area; // Center of gravity in y direction

    float vol = M_PI * pow(CG_y, 2) * (x[n - 1] - x[0]); // Volume of solid of revolution using disk method

    float area_bounded = 0;

    for (int i = 0; i < n - 1; i++)
    {
        area_bounded += y[i] * (x[i + 1] - x[i]); // Area bounded by the curve and x-axis
    }

    printf("Center of gravity: (%f, %f)\n", CG_x, CG_y);
    printf("Volume of solid of revolution: %f\n", vol);
    printf("Area bounded by the curve: %f\n", area_bounded);

    return 0;
}
