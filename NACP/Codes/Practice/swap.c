/*swapping digits in a numbers*/
#include<stdio.h>

int main(){
    int a;
    printf("Enter a number: ");
    scanf("%d", &a);
    int b = 0;
    while(a>0){
        int c = a%10;
        b = b*10 + c;
        a = a/10;
    }
    return 0;
}


/*
a = 1234
c = 4
b = 0*10 + 4 = 4
a = 1234/10 = 123

c = 3
b = 4*10 + 3 = 43
a = 123/10 = 12

c = 2
b = 43*10 + 2 = 432
a = 12/10 = 1

c = 1
b = 432*10 + 1 = 4321
a = 1/10 = 0



*/