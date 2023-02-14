#include <stdlib.h>
#include<stdio.h>
#include <math.h>
void main()
{
    float c[30][31], a, b, ce;
    int i, j = 0, k = 0, l, m, n, o, en;
    printf("\n\n Enter number of equations : ");
    scanf("%d", &en);
    for (i = 0; i < en; i++)
    {
        printf("\n Enter Coefficient of Unknown variables and then RHS of the %d Equation: ", (i + 1));
        for (j = 0; j < (en + 1); j++)
        {
            scanf("%f", &c[i][j]);
        }
    }

    i = 0;
    for (l = 0; l < (en - 1); l++)
    {

        for (k = 0; k < (en - 1); k++)
        {
            for (n = en; n >= 0; n--)
                c[i + 1][j + n] = c[i + 1][j + n] - (c[i + 1][j] / c[l][j]) * c[l][j + n];
            i++;
        }
        
        j++;
        i = 1;
    }
    printf("\n The inserted equations are :\n");   // Printing the equation in matrix form
        for (m = 0; m < en; m++)
        {
            for (o = 0; o < (en + 1); o++)
            {
                printf("\t %0.3f", c[m][o]);
            }
            printf("\n\n\n");
        }
}