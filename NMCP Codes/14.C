/*
The following table gives the distance in nautical miles of the visible horizon for the given heights in feet above the earth's surface.
x : 100, 150, 200, 250, 300, 350, 400
y: 10.63, 13.03, 15.04, 16.81, 18.42, 19.9, 21.27
Use Newton's forward formula to find y when x = 218 ft.

Write its computer programme in 'C' language
*/

#include <stdio.h>
#include <math.h>
int main()
{
    float x[] = {100, 150, 200, 250, 300, 350, 400};
    float y[] = {10.63, 13.03, 15.04, 16.81, 18.42, 19.9, 21.27};
    int n = sizeof(x) / sizeof(x[0]);
    float h = x[1] - x[0];
    float u = (218 - x[0]) / h;
    printf("%d\t\t%d\n",sizeof(x),sizeof(x[0]));
    // Create the divided difference table
    float dd[n][n];
    for (int i = 0; i < n; i++)
    {
        dd[i][0] = y[i];
    }
    for (int j = 1; j < n; j++)
    {
        for (int i = 0; i < n - j; i++)
        {
            dd[i][j] = dd[i + 1][j - 1] - dd[i][j - 1];
        }
    }

    // Print the divided difference table
    printf("Divided Difference Table:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%.2f\t", x[i]);
        for (int j = 0; j < n - i; j++)
        {
            printf("%.4f\t", dd[i][j]);
        }
        printf("\n");
    }
    // Use the divided difference table to interpolate y
    float res = dd[0][0];
    float factorial = 1;
    for (int j = 1; j < n; j++)
    {
        factorial *= j;
        res += (dd[0][j] * pow(u, j)) / factorial;
    }

    printf("The interpolated value of y for x = 218 is %.2f", res);
    return 0;
}

/*

#include <stdio.h>
#include <conio.h>

int main()
{
    float x[20], y[20][20];
    int i, j, n;
    clrscr();
    // /* Input Section
    printf("Enter number of data?\n");
    scanf("%d", &n);
    printf("Enter data:\n");
    for (i = 0; i < n; i++)
    {
        printf("x[%d]=", i);
        scanf("%f", &x[i]);
        printf("y[%d]=", i);
        scanf("%f", &y[i][0]);
    }

    // /* Generating Forward Difference Table
    for (i = 1; i < n; i++)
    {
        for (j = 0; j < n - i; j++)
        {
            y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
        }
    }

    // /* Displaying Forward Difference Table
    printf("\nFORWARD DIFFERENCE TABLE\n\n");
    for (i = 0; i < n; i++)
    {
        printf("%0.2f", x[i]);
        for (j = 0; j < n - i; j++)
        {
            printf("\t%0.2f", y[i][j]);
        }
        printf("\n");
    }

    // getch(); /* Holding Screen
    return 0;
}

*/