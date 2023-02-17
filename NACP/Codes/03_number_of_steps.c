/************************************************************************************************************************************
write a program to enter two int numbers and print n number of steps between them
*************************************************************************************************************************************/

#include<stdio.h>

int main(){
    int i,j,s,n;
    float d;

    printf("Enter the upper limit & lower limit: ");
    scanf("%d %d",&i,&j);
    printf("Enter the number of steps: ");
    scanf("%d",&s);
    d = (float)(j-i)/s;
    printf("The steps are: \n");
    for(n=0;n<=s;n++){
        printf("%f \t",i+d*n);
    }
    return 0;
}