// /*
// The following table gives the scores secured by 1OO students in the Numerical
// Analysis subject:
// Range of scores: below 40, below 50, below 60, below 70, below 80
// Number of students: 25 60 82 93 100
// Use Newton's forward difference interpolation formula to find.
// (i) the number of students who got scores more than 55.
// (ii) the number of students who secured scores in the range between 36 and 45.
// Write its computer programme in 'C' language
// */

// #include <stdio.h>

// double newton_forward_interpolation(double x[], double y[], int n, double x0) {
//     double f[n][n];
//     double y0 = 0;

//     // compute forward difference table
//     for (int i = 0; i < n; i++) {
//         f[i][0] = y[i];
//     }

//     for (int j = 1; j < n; j++) {
//         for (int i = 0; i < n-j; i++) {
//             f[i][j] = f[i+1][j-1] - f[i][j-1];
//         }
//     }

//     // interpolate using formula
//     double u = (x0 - x[0]) / (x[1] - x[0]);
//     double term = 1;
//     double factorial = 1;

//     y0 = f[0][0];

//     for (int j = 1; j < n; j++) {
//         term *= (u - j + 1);
//         factorial *= j;

//         y0 += (term / factorial) * f[0][j];
//     }

//     return y0;
// }

// int main() {
//     int n = 5;
//     double x[] = {40, 50, 60, 70, 80};
//     double y[] = {25, 60, 82, 93, 100};

//     // (i) number of students who got scores more than 55
//     double num_students_above_55 = newton_forward_interpolation(x, y, n, 55.0);
//     printf("Number of students who got scores more than 55: %.2lf\n", num_students_above_55);

//     // (ii) number of students who secured scores in the range between 36 and 45
//     double num_students_in_range = newton_forward_interpolation(x, y, n, 45.0) - newton_forward_interpolation(x, y, n, 36.0);
//     printf("Number of students who secured scores in the range between 36 and 45: %.2lf\n", num_students_in_range);

//     return 0;
// }
#include <stdio.h>
#include <stdlib.h>
double getPeople(int n,double d[n][n],double x[n], int xp){
    double p = d[0][0];
    double prod;
    for (int j = 1; j < n; j++) {
        prod = 1;
        for (int i = 0; i < j; i++) {
            prod *= (xp - x[i]);
        }
        p += d[j][j] * prod;
    }
    return p;
}
int main() {
    int n; // number of data points
    double r1,r2; // year to estimate population for

    // read number of data points from user input
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    // allocate memory for x and y arrays
    double x[n],y[n];

    // read x and y arrays from user input
    printf("Enter the x and y values for each data point:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &x[i], &y[i]);
    }

    printf("Enter the  first value of range: ");
    scanf("%lf",&r1);
    printf("Enter the second value of range: ");
    scanf("%lf",&r2);

    // construct divided difference table
    double d[n][n];
    for (int i = 0; i < n; i++) {
        d[i][0] = y[i];
    }
    for (int j = 1; j < n; j++) {
        for (int i = j; i < n; i++) {
            d[i][j] = (d[i][j-1] - d[i-1][j-1]) / (x[i] - x[i-j]);
        }
    }



    printf("Estimated number of between marks %lf - %lf is: %g\n", r1,r2, floor(getPeople(n,d,x,r2)-getPeople(n,d,x,r1)));

   return 0;
}