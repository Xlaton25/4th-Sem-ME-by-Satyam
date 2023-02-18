// printing n number of steps in between given range
#include<stdio.h>

int main(){
    float i,j,s,d;
    printf("Enter the 1st number, last number & number of steps : ");
    scanf("%f %f %f", &i, &j, &s);
    d = (j-i)/s; // calculating step value
    printf(" the steps are : ");
    // for(float k = i; k<=j; k+=d){
    //     printf("%.4f ", k);
    // }
    for(float k = 0; k<=s; k++){
        float h = i+k*d;
        printf("%.4f ", h);
    }
    return 0;
}
    