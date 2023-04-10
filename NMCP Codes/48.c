#include <stdio.h>
int main()
{
    int n;
    float sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, a, b;

    printf("Enter no of Observations : \n");
    scanf("%d", &n);

    float x[n], y[n], a_matrix[2][3];

    printf("Enter the values of x \n");
    for (int i = 0; i < n; i++)
        scanf("%f", &x[i]);

    printf("Enter the values of y \n");
    for (int i = 0; i < n; i++)
        scanf("%f", &y[i]);

    for (int i = 0; i < n; i++)
    {
        sum1 = sum1 + x[i];
        sum2 = sum2 + y[i];
        sum3 = sum3 + x[i] * y[i];
        sum4 = sum4 + x[i] * x[i];
    }
    a_matrix[0][0] = n;
    a_matrix[0][1] = sum1;
    a_matrix[0][2] = sum2;
    a_matrix[1][0] = sum1;
    a_matrix[1][1] = sum4;
    a_matrix[1][2] = sum3;

    int ratio = a_matrix[1][0] / a_matrix[0][0];
    for (int i = 0; i < 3; i++)

        a_matrix[1][i] = a_matrix[1][i] - ratio * a_matrix[0][i];

    printf("The upper triangular matrix : \n");

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%.2f ", a_matrix[i][j]);
        }
        printf("\n");
    }

    b = a_matrix[1][2] / a_matrix[1][1];
    a = (a_matrix[0][2] - a_matrix[0][1] * b) / a_matrix[0][0];
    printf("The equation of line : y = %.2f + %.2fx ", a, b);

    return 0;
}
