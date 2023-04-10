#include<stdio.h>

int main(){
    int num = 6;
    float x[6] = {1, 2, 3, 4, 6, 8};
    float y[6] = {2.4, 3.1, 3.5, 4.2, 5.0, 6.0};
    float x1Sum = 0, y1Sum = 0, x1y1Sum = 0, x2Sum = 0;
    int i = 0;
    for (i; i<num; i++){
        x1Sum = x1Sum + x[i];
        y1Sum = y1Sum + y[i];
        x1y1Sum = x1y1Sum + x[i]*y[i];
        x2Sum = x2Sum + x[i]*x[i];
    }
    printf("Equation 1: %0.4f = %da + %0.4fb\n", y1Sum, num, x1Sum);
    printf("Equation 2: %0.4f = %0.4fa + %0.4fb\n", x1y1Sum, x1Sum, x2Sum);
    printf("Solving these two equations:\n");
    float b = ((y1Sum/num)-(x1y1Sum/x1Sum))/((x1Sum/num)-(x2Sum/x1Sum));
    printf("Value of b: %0.4f\n", b);
    float a = (y1Sum-b*x1Sum)/num;
    printf("Value of a: %0.4f\n", a);
    printf("Required equation: y = %0.4f + %0.4fx", a, b);
}