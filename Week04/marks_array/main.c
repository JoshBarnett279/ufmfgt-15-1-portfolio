#include <stdio.h>

int main(void) {

    int size;

    do {
        printf("How many marks do you want to enter? \n\n");
        scanf("%d", &size);

        if (size <= 0) {
            printf("Invalid number. Please enter a number greater than 0.\n\n");
        }

    } while (size <= 0);

    int marks[size];
    int total = 0;
    float average;
    int highest, lowest;
    int i;

    for (i = 0; i < size; i++) {
        printf("Enter mark: \n\n%d:  ", i + 1);
        scanf("%d", &marks[i]);
    }

    highest = marks[0];
    lowest = marks[0];

    for (i = 0; i < size; i++) {
        total += marks[i];

        if (marks[i] > highest) {
            highest = marks[i];
        }

        if (marks[i] < lowest) {
            lowest = marks[i];
        }
    }

    average = total / (float) size;

    printf("\nAverage = %.2f\n", average);
    printf("Highest = %d\n", highest);
    printf("Lowest = %d\n", lowest);

    return 0;
}
