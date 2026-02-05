#include <stdio.h>

int main(void) {
    int number = -1;
    while (number < 0) {
        printf("Enter a positive number: \n");
        scanf("%d", &number);
    }

    printf("Valid number entered\n");

    return 0;
}
