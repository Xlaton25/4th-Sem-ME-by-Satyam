// sorting 10 int value in array
#include<stdio.h>

int main(){
    int a[10],i,j,k;
    char ch;
    printf("Enter 10 numbers: ");
    for(i = 0; i<10; i++){
        scanf("%d", &a[i]);
    }
    fflush(stdin); // clear the buffer
    printf("Enter 'a' for ascending order or 'd' for descending order: ");
    scanf("%c", &ch);
    if(ch == 'a'){
        for(i = 0; i<10; i++){
            for(j = i+1; j<10; j++){ //
                if(a[i]>a[j]){  // a[0] = 5 , a[1] = 4
                    k = a[i];   // k = 5
                    a[i] = a[j];// a[0] = 4
                    a[j] = k;  // a[1] = 5
                }
            }
        }
        
    }
    else if(ch == 'd'){
        for(i = 0; i<10; i++){
            for(j = i+1; j<10; j++){
                if(a[i]<a[j]){
                    k = a[i];
                    a[i] = a[j];
                    a[j] = k;
                }
            }
        }
    }

    else{
        printf("Invalid input");
    }
    printf("The sorted array is: ");
    for(i = 0; i<10; i++){
        printf("%d ", a[i]);
    }
    // printf("%d",ch);
    return 0;
}