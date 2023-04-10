#include <stdio.h>
#include <math.h>
#define e 0.0001

float func(float x)
{
    return (2*x-(log10(x))-7);
}

float rtf(float x1, float x2)
{
    return (x1 * func(x2) - x2 * func(x1)) / (func(x2) - func(x1));
}

int main()
{

    int it, i = 1;
    float x1, x2, x3, x;

    printf("Enter the maximum value of iterations : \n ");
    scanf("%d", &it);

    do
    {
        printf("Enter the value of x1 & x2 :\n");
        scanf("%f%f", &x1, &x2);
        if (func(x1) * func(x2) > 0)
        {
            printf("Roots are invalid \n");
            continue;
        }
        else
        {
            printf("Roots lies between %f & %f \n", x1, x2);
            break;
        }
    } while (1);

    x = rtf(x1, x2);
    do
    {
        if (func(x) * func(x1) < 0)
            x2 = x;
        else
            x1 = x;
        printf("Iterations = %d Root = %f \n", i, x);

            x3 = rtf(x1, x2);
        if (fabs(x3 - x) < e)
        {
            printf("Root = %f Total Iterations = %d ", x, i);
            return 0;
        }
        x3 = x;
        i++;
    } while (i <= it);

    printf("Root = %f Total Iterations = %d ", x, --i);

    return 0;
}
