#include <stdio.h>

int main(void) {
    int age;
    int hasID;

    printf("Please enter you age:\n\n");
    scanf("%d", &age);

    if (age >= 18) {

        printf("Do you have ID? (1 = yes, 0 = no) \n\n");
        scanf("%d", &hasID);

        if (hasID == 1) {
            printf("Entry allowed\n");
        }
        else {
            printf("ID required\n");
        }
    }
    else {
        printf("Too young\n");
    }

    return 0;
}
