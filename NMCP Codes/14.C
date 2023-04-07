/*
The following table gives the distance in nautical miles of the visible horizon for the given heights in feet above the earth's surface. 
x : 100, 150, 200, 250, 300, 350, 400
y: 10.63, 13.03, 15.04, 16.81, 18.42, 19.9, 21.27

Solve using Newton Interpolation method
Write its computer programme in 'C' language
*/

#include <stdio.h>

int main() {
    double x[] = {100, 150, 200, 250, 300, 350, 400};
    double y[] = {10.63, 13.03, 15.04, 16.81, 18.42, 19.9, 21.27};
    int n = sizeof(x)/sizeof(x[0]);

    // Calculate divided differences
    double dd[n][n];
    for (int i = 0; i < n; i++) {
        dd[i][0] = y[i];
    }
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n-j; i++) {
            dd[i][j] = (dd[i+1][j-1] - dd[i][j-1]) / (x[i+j] - x[i]);
        }
    }

    // Use divided differences to interpolate at x = 175 and x = 375
    double x1 = 218;
    // double x2 = 218;
    double interp1 = dd[0][0];
    double interp2 = dd[0][0];
    double prod1 = 1.0;
    double prod2 = 1.0;
    for (int i = 1; i < n; i++) {
        prod1 *= (x1 - x[i-1]);
        interp1 += dd[0][i] * prod1;
        
    }

    printf("The interpolated distance for a height of 175 feet is %.2lf nautical miles.\n", interp1);

    return 0;
}
