/*
C program that generates and prints the point coordinates of a circle or an ellipse based on user choice
*/
#include <stdio.h>
#include <math.h>

#define PI 3.14159265

int main()
{
    int a, b, n, i;
    float theta, x, y, rx, ry;
    char shape;

    // Get shape choice from user
    printf("Enter shape (C for circle, E for ellipse): ");
    scanf("%c", &shape);

    // Get input values from user
    printf("Enter x-radius (a): ");
    scanf("%d", &a);
    printf("Enter y-radius (b): ");
    scanf("%d", &b);
    printf("Enter number of points to generate: ");
    scanf("%d", &n);

    // Generate and print point coordinates
    printf("\nPoint coordinates:\n");
    for (i = 0; i < n; i++) {
        theta = i * 2 * PI / n;
        x = a * cos(theta);
        y = b * sin(theta);
        if (shape == 'E') {  // for ellipse
            printf("(%.2f, %.2f)\n", x, y);
        } else {  // for circle
            printf("(%.2f, %.2f)\n", x, y);
        }
    }

    return 0;
}

/***************************TEST CASE***********************
Enter shape (C for circle, E for ellipse): C
Enter x-radius (a): 5
Enter y-radius (b): 5
Enter number of points to generate: 8

Point coordinates:
(5.00, 0.00)
(3.54, 3.54)
(0.00, 5.00)
(-3.54, 3.54)
(-5.00, 0.00)
(-3.54, -3.54)
(-0.00, -5.00)
(3.54, -3.54)
****************************************************************/
