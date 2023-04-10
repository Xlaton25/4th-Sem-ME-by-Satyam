#include <stdio.h>
#include <math.h>

float func(float i){
    if (i==0){
        return 0;
    }
    if (i==1){
        return 0.5087;
    }
    if (i==2){
        return 0.7071;
    }
    if (i==3){
        return 0.8409;
    }
    if (i==4){
        return 0.9306;
    }
    if (i==5){
        return 0.9878;
    }
    if (i==6){
        return 1;
    }
}

int main(){
    float a = 0, b = 3.14159256/2, intv = 6;
    float h = (b-a)/intv;
    int i;
    float finalValue = func(a) + func(intv);
    for (i=1;i<6; i++){
        finalValue = finalValue + 2*(func(i));
    }
    finalValue = h*finalValue/2;
    printf("%0.4f", finalValue);
}