// printing star triangle pattern
#include<stdio.h>

int main(){
    int i,j,k;
    printf("Enter the number of rows: ");
    scanf("%d", &i);
    for(j = 1; j<=i; j++){
        for(k = 1; k<=(2*i-1); k++){ // 2*i-1 = 2*5-1 = 9
            if(k>=i-(j-1) && k<=i+(j-1)){ // k>= 5-(5-1) && k<=5+(5-1) 
            // k >= 1 && k <= 9  1 2 3 4 5 6 7 8 9
                printf("*");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}

/*
***************** ***********************
****************   **********************
***************     *********************
**************       ********************

*/