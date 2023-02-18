// convert to binary
/*

24 = 16 + 8 = 10000 + 1000 = 11000

*/
#include<stdio.h>

int main(){
    int a;
    printf("Enter a number: ");
    scanf("%d", &a); // taking input from user
    int b = 0; // binary number 
    int c = 1; 
    while(a>0){ 
        int d = a%2; // remainder
        b = b + d*c; // b = b + d*1
        c = c*10; 
        a = a/2;
    }
    printf("%d", b);

    return 0;
}