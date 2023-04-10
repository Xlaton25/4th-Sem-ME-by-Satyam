#include <stdio.h>
#include <math.h>

float func( float x){
    return sqrt(cos(x));
}

int main(){
    float x[9] = {0, 10, 20, 30, 40, 50, 60, 70, 80};
    float y[9] = {30, 31.63, 33.34, 35.47, 37.75, 40.33, 43.25, 46.69, 50.67};
    int  a = 0, b = 80, intv = 8;
    float h = (b-a)/intv;
    int i;
    float finalValue = y[0] + y[intv];
    for (i=1;i<9; i++){
        if ((i/2)%2==0){
            finalValue += 2*(y[i]);
        }
        else{
            finalValue += 4*(y[i]);
        }
    }
    finalValue = h*finalValue/3;
    printf("Velocity of the rocket at t = 80s is %0.4f", finalValue);
}