/*********************************************************************
print the Fibonacci series numbers within a range provided by the user
**********************************************************************/

#include <stdio.h>

int main() {
    int first = 0, second = 1, next;
    int range, temp;

    printf("Enter range to print Fibonacci series: ");
    scanf("%d", &range);

    // swap first and second if user enters range in reverse order
    if (first > second) {
        temp = first;
        first = second;
        second = temp;
    }

    printf("Fibonacci series up to %d: %d, %d", range, first, second);

    next = first + second;
    while (next <= range) {
        printf(", %d", next);
        first = second;
        second = next;
        next = first + second;
    }

    return 0;
}
