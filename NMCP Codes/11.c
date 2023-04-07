/* Find the value of sin 52 degree from the given table:
θ = 45 50 55 60
sin θ = 0.7071 0.7660 0.8192 0.8660
Use Newton's forward difference interpolation formula.
Write its computer programme in 'C' language
 */

#include <stdio.h>

double sin_interpolate(double x[], double y[], int n, double x0) {
    double y0 = 0.0;
    double u = (x0 - x[0])/(x[1] - x[0]);

    double d[n][n];

    // calculate forward difference table
    for (int i = 0; i < n; i++) {
        d[i][0] = y[i];
    }

    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n-j; i++) {
            d[i][j] = d[i+1][j-1] - d[i][j-1];
        }
    }

    // interpolate using formula
    y0 = y[0];

    for (int j = 1; j < n; j++) {
        double term = d[0][j];

        for (int i = 0; i < j; i++) {
            term *= (u - i)/(i+1);
        }

        y0 += term;
    }

    return y0;
}

int main() {
    int n = 4;
    double x[] = {45, 50, 55, 60};
    double y[] = {0.7071, 0.7660, 0.8192, 0.8660};
    double x0 = 52.0;
    double sin_x0 = sin_interpolate(x, y, n, x0);

    printf("sin %.2lf = %.4lf\n", x0, sin_x0);

    return 0;
}
