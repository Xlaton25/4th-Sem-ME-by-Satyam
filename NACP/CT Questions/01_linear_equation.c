/***************************************************
1. Write a program to solve 2 linear equations to know two unknown variables
****************************************************/
#include<stdio.h>
int main()
{
    int a1, b1, c1, a2, b2, c2;
    float res_x, res_y;
    printf("Enter the values for the first equation.");
    printf("Enter the value for a1  : ");
    scanf("%d",&a1);
    printf("Enter the value for b1  : ");
    scanf("%d",&b1);
    printf("Enter the value for c1  : ");
    scanf("%d",&c1);
    printf("Enter the values for the second equation.");
    printf("Enter the value for a2  : ");
    scanf("%d",&a2);
    printf("Enter the value for b2  : ");
    scanf("%d",&b2);
    printf("Enter the value for c2  : ");
    scanf("%d",&c2);
    printf("\nYour system of equations is the following:\n");
    printf("(%d)x+(%d)y=(%d)\n",a1,b1,c1);
    printf("(%d)x+(%d)y=(%d)\n",a2,b2,c2);

if ((a1 * b2) - (b1 * a2) == 0){
    printf("\nThe system has no solution.\n");
}
else{
    res_x = ((c1*b2) - (b1*c2))/((a1*b2)-(b1*a2));
    res_y = ((a1*c2) - (c1*a2)) / ((a1*b2) - (b1*a2));;
    printf("x = %f and y = %f",res_x,res_y);
}

    return 0;
}