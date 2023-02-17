/*************************************************************************************
C program that takes a number (maximum 5 digits) as input from the user and prints the number in words
*************************************************************************************/

#include <stdio.h>

void print_num_in_words(int num);

int main() {
    int num;

    printf("Enter a number (maximum 5 digits): "); // The user is prompted to enter a number (maximum 5 digits).
    scanf("%d", &num); // The program reads the input number and stores it in the num variable.

    print_num_in_words(num); // The program calls the print_num_in_words function and passes the num variable as an argument.

    return 0;
}

void print_num_in_words(int num) // The program defines the print_num_in_words function.
{ 
    // Array of strings to store the names of numbers from 1 to 19
    const char* ones[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

    // Array of strings to store the names of multiples of 10 from 20 to 90
    const char* tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

    if (num == 0) {
        printf("zero");
    } else if (num < 0) {
        printf("minus ");
        print_num_in_words(-num);
    } else if (num < 20) {
        printf("%s", ones[num]);
    } else if (num < 100) {
        printf("%s", tens[num / 10]);
        if (num % 10 != 0) {
            printf("-%s", ones[num % 10]);
        }
    } else if (num < 1000) {
        printf("%s hundred", ones[num / 100]);
        if (num % 100 != 0) {
            printf(" and ");
            print_num_in_words(num % 100);
        }
    } else if (num < 100000) {
        print_num_in_words(num / 1000);
        printf(" thousand");
        if (num % 1000 != 0) {
            printf(" ");
            print_num_in_words(num % 1000);
        }
    } else {
        printf("Invalid input!");
    }
}
