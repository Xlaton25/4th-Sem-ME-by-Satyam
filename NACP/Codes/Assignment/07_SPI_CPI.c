/******************************************************************************************
C program that prints a semester marksheet along with the calculation of the SPI (Semester Performance Index) and CPI (Cumulative Performance Index)
*******************************************************************************************/

#include <stdio.h>

int main() {
    int n, i;
    float spi, cpi, total_credits = 0, total_grade_points = 0, last_sem_credits, last_sem_cpi;
    char grade;

    printf("Enter last semester CPI and credits: ");
    scanf("%f %f", &last_sem_cpi, &last_sem_credits);

    printf("Enter number of subjects: ");
    scanf("%d", &n);

    printf("\n");

    for (i = 1; i <= n; i++) {
        int credits;
        float marks, grade_points;
        printf("Enter marks and credits for subject %d: ", i);
        scanf("%f %d", &marks, &credits);

        if (marks >= 90) {
            grade = 'S';
            grade_points = 10.0;
        } else if (marks >= 80) {
            grade = 'A';
            grade_points = 9.0;
        } else if (marks >= 70) {
            grade = 'B';
            grade_points = 8.0;
        } else if (marks >= 60) {
            grade = 'C';
            grade_points = 7.0;
        } else if (marks >= 50) {
            grade = 'D';
            grade_points = 6.0;
        } else if (marks >= 40) {
            grade = 'E';
            grade_points = 5.0;
        } else {
            grade = 'F';
            grade_points = 0.0;
        }

        printf("Grade for subject %d: %c\n", i, grade);
        printf("Grade points for subject %d: %0.2f\n", i, grade_points);
        printf("\n");

        total_credits += credits;
        total_grade_points += grade_points * credits;
    }

    spi = total_grade_points / total_credits;
    cpi = (spi * total_credits + last_sem_cpi * last_sem_credits) / (total_credits + last_sem_credits);

    printf("Total credits: %0.2f\n", total_credits);
    printf("Total grade points: %0.2f\n", total_grade_points);
    printf("SPI: %0.2f\n", spi);
    printf("CPI: %0.2f\n", cpi);

    return 0;
}

/***********************TEST CASE***************************

Enter last semester CPI and credits: 8.0 20
Enter number of subjects: 5

Enter marks and credits for subject 1: 82 4
Grade for subject 1: A
Grade points for subject 1: 9.00

Enter marks and credits for subject 2: 70 3
Grade for subject 2: B
Grade points for subject 2: 8.00

Enter marks and credits for subject 3: 64 4
Grade for subject 3: C
Grade points for subject 3: 7.00

Enter marks and credits for subject 4: 92 3
Grade for subject 4: S
Grade points for subject 4: 10.00

Enter marks and credits for subject 5: 48 3
Grade for subject 5: E
Grade points for subject 5: 5.00

Total credits: 17.00
Total grade points: 152.00
SPI: 8.94
CPI: 8.29

***********************************************************/