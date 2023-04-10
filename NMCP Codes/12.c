/* From the following table of half-yearly premiums for policies maturing at different ages, estimate the premium for policies maturing at age of 46.

Age : 45, 50, 55, 60, 65
premium(In dollars) : 114.84, 96.16, 83.32, 74.48, 68.48
Write its computer programme in 'C' language
*/

// #include <stdio.h>

// int main() {
//     int age[] = {45, 50, 55, 60, 65};
//     double premium[] = {114.84, 96.16, 83.32, 74.48, 68.48};
//     int n = sizeof(age)/sizeof(age[0]);

//     int i = 0;
//     while (age[i] < 46 && i < n-1) {
//         i++;
//     }

//     if (i == 0) {
//         printf("Age 46 is below the minimum age.\n");
//     } else if (i == n-1) {
//         printf("Age 46 is above the maximum age.\n");
//     } else {
//         double slope = (premium[i] - premium[i-1]) / (age[i] - age[i-1]);  //
//         double est_premium = premium[i-1] + slope * (46 - age[i-1]);
//         printf("The estimated premium for age 46 is %.2lf dollars.\n", est_premium);
//     }

//     return 0;
// }

#include <stdio.h>

double newton_forward_interpolation(double x[], double y[], int n, double x0)
{
    double y0 = 0;
    double f[n][n];

    // compute forward difference table
    for (int i = 0; i < n; i++)
    {
        f[i][0] = y[i];
    }

    for (int j = 1; j < n; j++)
    {
        for (int i = 0; i < n - j; i++)
        {
            f[i][j] = f[i + 1][j - 1] - f[i][j - 1];
        }
    }

    // print forward difference table
    printf("Forward Difference Table:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%.2lf\t", x[i]);
        for (int j = 0; j < n - i; j++)
        {
            printf("%.2lf\t", f[i][j]);
        }
        printf("\n");
    }

    // interpolate using formula
    double u = (x0 - x[0]) / (x[1] - x[0]);
    double term = 1;
    double factorial = 1;

    y0 = f[0][0];

    for (int j = 1; j < n; j++)
    {
        term *= (u - j + 1);
        factorial *= j;

        y0 += (term / factorial) * f[0][j];
    }

    return y0;
}

int main()
{
    int n = 5;
    double x[] = {45, 50, 55, 60, 65};
    double y[] = {114.84, 96.16, 83.32, 74.48, 68.48};
    double x0 = 46.0;
    double premium = newton_forward_interpolation(x, y, n, x0);

    printf("Premium for policy maturing at age %.2lf = $%.2lf\n", x0, premium);

    return 0;
}
