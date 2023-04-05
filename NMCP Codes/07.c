// Compute one positive root of 2x — log_10(x) = 7 by the Newton-Raphson method correct to four decimal places. Write its computer programme in 'C' language.

#include<stdio.h>
#include<math.h>

#define f(x) (2*x-log10(x)) //function
#define df(x) (2+(1/(x*log(10)))) //derivative of function

int main()
{
    double x0, x1;
    printf("Enter the value of x0: ");
    scanf("%lf", &x0);
    
    do
    {
        x1 = x0 - (f(x0) / df(x0));
        if(fabs((x1 - x0) / x1) < 0.0001) //for correct to four decimal places
        {
            break; 
        }
        x0 = x1;
    }while(1);

    printf("\nThe positive root is %lf\n", x1);
    return 0;
}
