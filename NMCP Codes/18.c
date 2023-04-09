/*
The table given below reveals the velocity 'v' of a body during the
time 't' specified. Find its acceleration at t = 1.1, Using Newton's formula for interpolation.
t: 1.0, 1.1, 1.2, 1.3, 1.4
v: 43.1, 47.7, 52.1, 56.4, 60.8

Write its computer programme in 'C' language
*/

// #include <stdio.h>
// #include <math.h>

// int main() {
//     double x[] = {1.0, 1.1, 1.2, 1.3, 1.4};
//     double y[] = {43.1, 47.7, 52.1, 56.4, 60.8};
//     double u = (1.1 - x[0]) / (x[1] - x[0]);
//     double dy[5][5];
//     int i, j;

//     for (i = 0; i < 5; i++) {
//         dy[i][0] = y[i];
//     }

//     for (j = 1; j < 5; j++) {
//         for (i = 0; i < 5 - j; i++) {
//             dy[i][j] = dy[i+1][j-1] - dy[i][j-1];
//         }
//     }

//     printf("Difference Table:\n\n");
//     for (i = 0; i < 5; i++) {
//         printf("%.1f\t", x[i]);
//         for (j = 0; j < 5 - i; j++) {
//             printf("%.4f\t", dy[i][j]);
//         }
//         printf("\n");
//     }

//     double sum = dy[0][0];
//     double prod = 1;
//     for (j = 1; j < 5; j++) {
//         prod *= (u-j+1) / j;
//         sum += prod * dy[0][j];
//     }

//     printf("\nAcceleration at t = 1.1: %f\n", sum);
//     return 0;
// }

#include <stdio.h>

int main() {
    // given data
    float t[] = {1.0, 1.1, 1.2, 1.3, 1.4};
    float v[] = {43.1, 47.7, 52.1, 56.4, 60.8};
    int n = sizeof(t)/sizeof(t[0]);
    
    // calculate divided differences
    float div_diff[n][n];
    for (int i = 0; i < n; i++) {
        div_diff[i][0] = v[i];
    }
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n-j; i++) {
            div_diff[i][j] = (div_diff[i+1][j-1] - div_diff[i][j-1])/(t[i+j] - t[i]);
        }
    }
    
    // use Newton's formula for interpolation to find f(1.1) and f'(1.1)
    float x = 1.1;
    float y = div_diff[0][0];
    float dy = div_diff[0][1];
    float ddy = 2*div_diff[0][2];
    float prod = 1.0;
    for (int i = 0; i < n-1; i++) {
        prod *= (x - t[i]);
        y += div_diff[0][i+1]*prod;
        if (i > 0) {
            dy += div_diff[0][i+1]*prod;
        }
    }
    
    // print the results
    printf("f(1.1) = %.4f\n", y);
    printf("f'(1.1) = %.4f\n", dy);
    printf("The acceleration at t = 1.1 is %f m/s^2\n", dy);
    
    return 0;
}
