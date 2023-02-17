/*
to find the day of any date inserted by the user and to calculate the date after adding or subtracting a number of days
*/

#include <stdio.h>
#include <string.h>

int isLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return 1;
            }
            else {
                return 0;
            }
        }
        else {
            return 1;
        }
    }
    else {
        return 0;
    }
}

int getDayOfWeek(int day, int month, int year) {
    int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    year -= month < 3;
    return (year + year/4 - year/100 + year/400 + t[month-1] + day) % 7;
}

int getDaysInMonth(int month, int year) {
    int days;
    switch (month) {
        case 2:
            if (isLeapYear(year)) {
                days = 29;
            }
            else {
                days = 28;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            days = 30;
            break;
        default:
            days = 31;
    }
    return days;
}

void printDayOfWeek(int dayOfWeek) {
    switch (dayOfWeek) {
        case 0:
            printf("Sunday\n");
            break;
        case 1:
            printf("Monday\n");
            break;
        case 2:
            printf("Tuesday\n");
            break;
        case 3:
            printf("Wednesday\n");
            break;
        case 4:
            printf("Thursday\n");
            break;
        case 5:
            printf("Friday\n");
            break;
        case 6:
            printf("Saturday\n");
            break;
    }
}

int main() {
    int day, month, year;
    printf("Enter a date (DD/MM/YYYY): ");
    scanf("%d/%d/%d", &day, &month, &year);

    int dayOfWeek = getDayOfWeek(day, month, year);
    printf("The day of the entered date is: ");
    printDayOfWeek(dayOfWeek);

    int numDays;
    printf("Enter number of days to add(+)/subtract(-): ");
    scanf("%d", &numDays);
    int y = numDays;
    int daysInMonth;
    while (numDays != 0) {
        if (numDays > 0) {
            day++;
            if (day > (daysInMonth = getDaysInMonth(month, year))) {
                day = 1;
                month++;
                if (month > 12) {
                    month = 1;
                    year++;
                }
            }
            numDays--;
        }
        else {
            day--;
            if (day == 0) {
                month--;
                if (month == 0) {
                    month = 12;
                    year--;
                }
                daysInMonth = getDaysInMonth(month, year);
                day = daysInMonth;
            }
            numDays++;
        }
    }

    printf("The date after adding/subtracting %d days is: %02d/%02d/%d\n", y, day, month, year);

    return 0;
}
