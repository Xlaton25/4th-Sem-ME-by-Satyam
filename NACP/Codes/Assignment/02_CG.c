/***********************************************************************************************
C program that finds the center of gravity (CG) of a triangle whose sides are given by the user
***********************************************************************************************/


#include <stdio.h>
#include <math.h>

int main() {
    float x1, y1, x2, y2, x3, y3;
    float a, b, c; // Lengths of sides
    float cx, cy; // Coordinates of center of gravity

    // Read the coordinates of the vertices
    printf("Enter the coordinates of the first vertex (x1 y1): ");
    scanf("%f %f", &x1, &y1);

    printf("Enter the coordinates of the second vertex (x2 y2): ");
    scanf("%f %f", &x2, &y2);

    printf("Enter the coordinates of the third vertex (x3 y3): ");
    scanf("%f %f", &x3, &y3);

    // Compute the lengths of the sides
    a = sqrt(pow((x2-x1), 2) + pow((y2-y1), 2));
    b = sqrt(pow((x3-x2), 2) + pow((y3-y2), 2));
    c = sqrt(pow((x1-x3), 2) + pow((y1-y3), 2));

    // Compute the coordinates of the center of gravity
    cx = (x1 + x2 + x3) / 3.0;
    cy = (y1 + y2 + y3) / 3.0;

    // Print the coordinates of the center of gravity
    printf("The center of gravity is at (%f, %f).\n", cx, cy);

    return 0;
}
