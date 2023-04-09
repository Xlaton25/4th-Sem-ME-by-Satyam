/*
Evaluate integration of (t/(5.2*t)) from -2 to 2 by Trapezoidal rule. Also write its programme in 'C language.
*/

#include <stdio.h>

float f(float x){
    return (x / (5.2 * x));
}

int main(){
    float a = -2, b = 2;
    int n = 1;
    float h = (b - a) / n;
    float sum = 0;

    sum = f(a) + f(b);
    sum *= (h / 2);

    printf("The value of the integration is: %.4f", sum);

    return 0;
}
