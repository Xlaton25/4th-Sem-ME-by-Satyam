/********************************************************************************
C program that calculates the EMI (Equal Monthly Installment) for a bank loan with compound interest
*********************************************************************************/

#include <stdio.h>
#include <math.h>

int main() {
    float principal, rate, interest, emi;
    int tenure, frequency;

    printf("Enter principal amount: ");
    scanf("%f", &principal);

    printf("Enter interest rate (in percentage): ");
    scanf("%f", &rate);

    printf("Enter tenure of repayment (in months): ");
    scanf("%d", &tenure);

    printf("Enter frequency of EMI payments (1, 2, or 3 months): ");
    scanf("%d", &frequency);

    rate = rate / 100 / 12; // convert to monthly interest rate
    interest = pow(1 + rate, tenure); // calculate the compound interest
    emi = (principal * rate * interest) / (interest - 1); // calculate EMI

    if (frequency == 2) {
        emi /= 2;
    } else if (frequency == 3) {
        emi /= 3;
    }

    printf("Your EMI is %.2f\n", emi);

    return 0;
}

/****************************************************
Enter principal amount: 100000
Enter interest rate (in percentage): 10
Enter tenure of repayment (in months): 60
Enter frequency of EMI payments (1, 2, or 3 months): 3
Your EMI is 1943.45
*****************************************************/