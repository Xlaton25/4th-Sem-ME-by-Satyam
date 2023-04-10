#include <stdio.h>

float func(float x, float y){
    return -1*x*y*y;
}

int main(){
    float x0 = 0.4, y0 = 1.7231;
    float h = 0.2;
    float k1, k2, k3, k4;
    float finalX = 0.6;
    float n = ((finalX - x0) / h);
    int i = 0;
    for (i; i<n; i++){
        k1 = h*func(x0, y0);
        k2 = h*func(x0+ h/2, y0 + k1/2);
        k3 = h*func(x0+ h/2, y0 + k2/2);
        k4 = h*func(x0+ h, y0 + k3);
        y0 = y0 + (k1 + 2*k2 + 2*k3 + k4)/6;
        x0 = x0 + h;
        printf("For x= %0.4f, y = %0.4f\n", x0, y0);
    }
}