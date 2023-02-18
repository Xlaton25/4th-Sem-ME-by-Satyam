// program for prime number and composite number
#include<stdio.h>

int main(){
    int a;
    printf("Enter a number: ");
    scanf("%d", &a);
    int count = 0;
    if(a == 2){
        printf("Prime Number");
        return 0; // exit
    }
    for(int i = 1; i<a; i++){
        if(a%i==0){
            printf("Composite number");
            break;
        }
        else 
            count++; // count = count + 1;
    }
    if(count > 0){
        printf("Prime number");
    }
    return 0;
}

/*
**************
0 1 2 
a % 2 == 0 ?
a == 2? printf 
else composite 4 6 8 10 
break;
**************
count = 0;
a = 43  factors 1 43
for(int i = 2; i<a; ){
    if(a%i==0){
        printf("Composite number");
        break;
    }
    else 
        count++; // count = count + 1;
    i++;
}
if(count > 0){
    printf("Prime number");
}

*/