#include <stdio.h>

int main()
{

    int n, i, count = 0;
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    // 0 and 1 are not prime numbers
    if (n == 0 || n == 1)
        count = 1;

    for (i = 2; i <= n / 2; i++)
    {

        // condition for non-prime number
        // n is divisible by any number between 2 and n/2

        if (n % i == 0)
        {
            count = 1;
            break;
        }
    }

    if (count == 0)
        printf("%d is a prime number.", n);
    else
        printf("%d is not a prime number.", n);

    return 0;
}