#include <stdio.h>
#include <math.h>

int main(){
    float x[7] = {0, 2, 4, 6, 8, 10, 12};
    float y[7] = {0, 22, 30, 27, 18, 7, 0};
    float a = 0, b = 12;
    int intv = 6;
    float h = (b-a)/intv;
    int i;
    float finalValue = y[0] + y[intv];
    for (i=1;i<6; i++){
        if (i%3==0){
            finalValue += 2*(y[i]);
        }
        else{
            finalValue += 4*(y[i]);
        }
    }
    finalValue = h*finalValue/2;
    printf("Distance covered bv the car = %0.2f KM",finalValue);
}