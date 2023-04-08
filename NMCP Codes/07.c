// Compute one positive root of 2x — log_10(x) = 7 by the Newton-Raphson method correct to four decimal places. Write its computer programme in 'C' language.


#include <stdio.h>
#include <math.h>

// double f(double x) {
//     return (2*x - log10(x) - 7);
// }

// double df(double x) {
//     return (2 + 1/x);
// }
#define f(x) (2*x - log10(x) - 7)
#define df(x) (2 + 1/x)

int main() {
    double x0, x1, error = 0.0001;
    int i = 0,step = 1;

    printf("Enter an initial guess: ");
    scanf("%lf", &x0);
    printf("\nStep\t\tx0\t\tf(x0)\t\tx1\t\tf(x1)\n");
    do {
        // x1 = x0 - f(x0)/df(x0);
        // error = fabs((x1 - x0)/x1);
        // printf("%d\t\t%f\t%f\t%f\t%f\n",step,x0,f(x0),x1,df(x0));
        // x0 = x1;
        // i++;
        // step++;

        x1 = x0 - (f(x0) / df(x0));
        if(fabs((x1 - x0) / x1) < error) //for correct to three decimal places
        {
            break; 
        }
        printf("%d\t\t%f\t%f\t%f\t%f\n",step,x0,f(x0),x1,df(x0));
        x0 = x1;
        step++;
    } while (1); 

    printf("The positive root is approximately %.4lf\n", x1);
    
    return 0;
}

