// printing all the factors of a number
/*
a = 15
factors = 1 3 5 15
for(int i = 1; i<=a; i++){
    if(a%i==0){
        printf("%d ", i);
    }
}
*/
#include<stdio.h>

int main(){
    int a;
    printf("Enter a number: ");
    scanf("%d", &a);
    printf("Factors of %d are: ", a);
    for(int i = 1; i<=a; i++){
        if(a%i==0){
            printf("%d ", i);
        }
    }
    return 0;
}