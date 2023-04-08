/*
The following table gives the scores secured by 1OO students in the Numerical
Analysis subject:
Range of scores: 30—40 40—50 50—60 60—70 70-80
Number of students: 25 35 22 11 7
Use Newton's forward difference interpolation formula to find.
(i) the number of students who got scores more than 55.
(ii) the number of students who secured scores in the range between 36 and 45.
Write its computer programme in 'C' language
*/

#include <stdio.h>

double interpolate(double x[], double y[], int n, double x0) {
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
    int n = 5;
    double x[] = {35, 45, 55, 65, 75};
    double y[] = {25, 35, 22, 11, 7};

    // (i) number of students who got scores more than 55
    double num_above_50 = 0.0;

    for (int i = 2; i < n; i++) {
        num_above_50 += y[i-1];
    }

    double num_more_than_55 = interpolate(x, y, n, 56) + num_above_50;

    printf("Number of students who got scores more than 55: %.2lf\n", num_more_than_55);

    // (ii) number of students who secured scores in the range between 36 and 45
    double num_below_40 = y[0] + y[1];

    double num_between_36_45 = interpolate(x, y, 3, 37) - num_below_40;

    printf("Number of students who secured scores between 36 and 45: %.2lf\n", num_between_36_45);

    return 0;
}
