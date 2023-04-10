//Find the root of the equation xe^x = cos x in the interval (0, 1) using Regular-Falsi method correct to four decimal places. Write its computer programme in 'C' language.

// #include <stdio.h>
// #include <math.h>

// #define MAX_ITER 100 // Maximum number of iterations
// #define EPSILON 0.0001 // Error tolerance

// double f(double x, double e) {
//     return pow(x,e) - cos(x);
// }

// int main() {
//     double a = 0, b = 1, c, fa, fb, fc;
//     int iter = 0;

//     do {
//         fa = f(a,1.5);
//         fb = f(b,1.5);

//         c = a - ((fa*(b-a))/(fb-fa));
//         fc = f(c,1.5);

//         if (fa * fc < 0) {
//             b = c;
//         } else {
//             a = c;
//         }

//         iter++;
//     } while (fabs(fc) > EPSILON && iter < MAX_ITER);

//     if (iter == MAX_ITER) {
//         printf("Failed to find root within %d iterations\n", MAX_ITER);
//     } else {
//         printf("Root: %.4f\n", c);
//     }

//     return 0;
// }


/*
1. Initialize variables a and b as 0 and 1 respectively.
2. Compute f(a) = a^e - cos(a) and f(b) = b^e - cos(b).
3. Repeat the following steps until the root is found or the maximum number of iterations is reached:
        Compute the value of c using the formula: c = a - ((f(a)*(b-a))/(f(b)-f(a)))
        Compute f(c) = c^e - cos(c)
        If f(c) is very close to zero, then c is the root of the equation. Exit the loop and return the value of c.
        If f(c) has the same sign as f(a), then set a = c, else set b = c.
        If the maximum number of iterations is reached and a root has not been found, then print an error message.
*/



#include <stdio.h>
#include <math.h>
#define e 2.71828
#define T 0.0001

double f(double x) {
    return   cos(x) - x * pow(e, x);
}

int main() {
    double x0 = 0, x1 = 1, x2, f0, f1, f2;
    int i = 0;
    
    do {
        f0 = f(x0);
        f1 = f(x1);
        x2 = x1 - (f1 * (x1 - x0)) / (f1 - f0);
        f2 = f(x2);
        
        if (f2 == 0) {
            break;
        }
        
        if (f0 * f2 < 0) {
            x1 = x2;
        } else {
            x0 = x2;
        }
        
        i++;
    } while (fabs(x1 - x0) > T && i < 100);
    
    printf("The root of x^e = cos(x) in the interval (0, 1) is: %0.4lf", x2);
    
    return 0;
}
