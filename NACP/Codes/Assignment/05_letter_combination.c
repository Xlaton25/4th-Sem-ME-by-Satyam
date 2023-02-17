/********************************************************************************
C program to generate all possible 2, 3, 4, or 5 letter combinations of a set of 5 characters entered by the user
*********************************************************************************/

#include <stdio.h>
#include <string.h>

void print_combinations(char *arr, int size, int count);

int main() {
    char arr[6];
    int i, count;

    printf("Enter 5 alphabets: ");
    scanf("%s", arr);

    printf("Enter the length of combinations (2, 3, 4, or 5): ");
    scanf("%d", &count);

    printf("All possible %d-letter combinations are:\n", count);
    print_combinations(arr, strlen(arr), count);

    return 0;
}

void print_combinations(char *arr, int size, int count) {
    int i, j, k, l;

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (count >= 2) {
                printf("%c%c ", arr[i], arr[j]);
            }
            for (k = 0; k < size; k++) {
                if (count >= 3) {
                    printf("%c%c%c ", arr[i], arr[j], arr[k]);
                }
                for (l = 0; l < size; l++) {
                    if (count >= 4) {
                        printf("%c%c%c%c ", arr[i], arr[j], arr[k], arr[l]);
                    }
                    if (count == 5) {
                        printf("%c%c%c%c%c ", arr[i], arr[j], arr[k], arr[l], arr[l+1]);
                    }
                }
            }
        }
    }
    printf("\n");
}
