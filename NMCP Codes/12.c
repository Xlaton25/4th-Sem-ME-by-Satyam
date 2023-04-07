/* From the following table of half-yearly premiums for policies maturing at different ages, estimate the premium for policies maturing at age of 46.

Age : 45, 50, 55, 60, 65
premium(In dollars) : 114.84, 96.16, 83.32, 74.48, 68.48
Write its computer programme in 'C' language
*/

#include <stdio.h>

int main() {
    int age[] = {45, 50, 55, 60, 65};
    double premium[] = {114.84, 96.16, 83.32, 74.48, 68.48};
    int n = sizeof(age)/sizeof(age[0]);

    int i = 0;
    while (age[i] < 46 && i < n-1) {
        i++;
    }

    if (i == 0) {
        printf("Age 46 is below the minimum age.\n");
    } else if (i == n-1) {
        printf("Age 46 is above the maximum age.\n");
    } else {
        double slope = (premium[i] - premium[i-1]) / (age[i] - age[i-1]);
        double est_premium = premium[i-1] + slope * (46 - age[i-1]);
        printf("The estimated premium for age 46 is %.2lf dollars.\n", est_premium);
    }

    return 0;
}
