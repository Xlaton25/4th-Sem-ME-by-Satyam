// #include<stdio.h> // Preprocessor directive to include standard input output header file
// #include<math.h> // Preprocessor directive to include math header file

// int main(){
//     /*
//     %d for integer
//     %f for float
//     %c for character
//     %s for string
//     %ld for long integer
//     %lf for long float
//     %lld for long long integer
    
//     */



//     int a;
//     printf("Enter a number: ");
//     scanf("%d", &a);
//     printf("%d", a%2);
//     return 0;
// }


// program for even odd number
#include<stdio.h> //
int main(){ // main function
    int a; // variable declaration
    printf("Enter a number: ");
    scanf("%d", &a); // taking input from user
    if(a%2==0){
        printf("Even number");
    }
    else{
        printf("Odd number");
    }
    return 0;
}

/*
a = 5 // assignment operator
a = 5 // invalid
a == 5 // comparison operator


*/