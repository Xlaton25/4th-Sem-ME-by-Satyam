// By using Newton-Raphson's method, find the root of x^4 —x — 10 = 0 which is near to x = 2,correct to three decimal places.

#include<stdio.h>
#include<math.h>

#define f(x) (x*x*x*x-x-10)
#define df(x) (4*x*x*x-1)

int main()
{
    double x0 = 2, x1, e=0.001;
    int step = 1;
    printf("\nStep\t\tx0\t\tf(x0)\t\tx1\t\tf(x1)\n");
    do
    {
        x1 = x0 - (f(x0) / df(x0));
        if(fabs((x1 - x0) / x1) < e) //for correct to three decimal places
        {
            break; 
        }
        printf("%d\t\t%f\t%f\t%f\t%f\n",step,x0,f(x0),x1,df(x0));
        x0 = x1;
        step++;
    }while(1);

    printf("\nThe root is %lf", x1);
    return 0;
}
