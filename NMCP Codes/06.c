// By using Newton-Raphson's method, find the root of x^4 —x — 10 = 0 which is near to x = 2,correct to three decimal places.

#include<stdio.h>
#include<math.h>

#define f(x) (x*x*x*x-x-10)
#define df(x) (4*x*x*x-1)

int main()
{
    double x0 = 2, x1;
    do
    {
        x1 = x0 - (f(x0) / df(x0));
        if(fabs((x1 - x0) / x1) < 0.0001) //for correct to three decimal places
        {
            break; 
        }
        x0 = x1;
    }while(1);

    printf("\nThe root is %lf", x1);
    return 0;
}
