#include <stdio.h>

int main()
{
    float matrix[4][4];
    float det;

    // input the matrix
    printf("Enter the elements of the 4x4 matrix:\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            scanf("%f", &matrix[i][j]);
        }
    }

    // calculate the determinant
    det = matrix[0][0] * (matrix[1][1] * matrix[2][2] * matrix[3][3] + matrix[2][1] * matrix[3][2] * matrix[1][3] + matrix[3][1] * matrix[1][2] * matrix[2][3] - matrix[1][1] * matrix[3][2] * matrix[2][3] - matrix[3][1] * matrix[2][2] * matrix[1][3] - matrix[2][1] * matrix[1][2] * matrix[3][3]) - matrix[0][1] * (matrix[1][0] * matrix[2][2] * matrix[3][3] + matrix[2][0] * matrix[3][2] * matrix[1][3] + matrix[3][0] * matrix[1][2] * matrix[2][3] - matrix[1][0] * matrix[3][2] * matrix[2][3] - matrix[3][0] * matrix[2][2] * matrix[1][3] - matrix[2][0] * matrix[1][2] * matrix[3][3]) + matrix[0][2] * (matrix[1][0] * matrix[2][1] * matrix[3][3] + matrix[2][0] * matrix[3][1] * matrix[1][3] + matrix[3][0] * matrix[1][1] * matrix[2][3] - matrix[1][0] * matrix[3][1] * matrix[2][3] - matrix[3][0] * matrix[2][1] * matrix[1][3] - matrix[2][0] * matrix[1][1] * matrix[3][3]) - matrix[0][3] * (matrix[1][0] * matrix[2][1] * matrix[3][2] + matrix[2][0] * matrix[3][1] * matrix[1][2] + matrix[3][0] * matrix[1][1] * matrix[2][2] - matrix[1][0] * matrix[3][1] * matrix[2][2] - matrix[3][0] * matrix[2][1] * matrix[1][2] - matrix[2][0] * matrix[1][1] * matrix[3][2]);

    // output the determinant
    printf("The determinant of the matrix is %.2f\n", det);

    return 0;
}
