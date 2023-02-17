/***************************************************************************************************
C program that finds any number up to 5 digits whose cube of digit summation is equal to that number
****************************************************************************************************/


#include <stdio.h> // The program uses the standard input/output library.

int main() {   // The program starts executing from the main function.
    int num, temp, digit, sum; // The program declares the variables num, temp, digit, and sum.

    printf("Enter a number (up to 5 digits): ");    // The user is prompted to enter a number (up to 5 digits).
    scanf("%d", &num);    // The program reads the input number and stores it in the num variable.

    temp = num;  // The program initializes a temp variable with the value of num and a sum variable with the value of 0.
    sum = 0; 

    while (temp > 0) {
        digit = temp % 10;
        sum += (digit * digit * digit);    // The program calculates the cube of each digit and adds it to the sum variable.
        temp /= 10;   // The program removes the last digit from the temp variable.
    }

    if (sum == num) {   // The program checks if the sum of the cubes of the digits is equal to the number entered by the user.
        printf("%d is an Armstrong number.", num);   // If the sum of the cubes of the digits is equal to the number entered by the user, the program prints the number is an Armstrong number.
    } else {
        printf("%d is not an Armstrong number.", num);  // If the sum of the cubes of the digits is not equal to the number entered by the user, the program prints the number is not an Armstrong number.
    }

    return 0;  // The program terminates.
}
