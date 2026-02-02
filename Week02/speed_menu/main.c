#include <stdio.h>
#include <synchapi.h>

int main(void) {
    int choice;
    float speed;
    float speed_ms;
    float speed_mph;

    do {
        printf("\nMenu:\n");
        printf("1. Check speed\n");
        printf("2. Convert m/s to mph\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter speed in mph: ");
                scanf("%f", &speed);

                if (speed < 0) {
                    printf("Invalid speed\n");
                } else if (speed > 70) {
                    printf("Speeding\n");
                } else {
                    printf("Valid speed\n");
                }
                break;

            case 2:
                printf("Enter speed in m/s: ");
                scanf("%f", &speed_ms);

                speed_mph = speed_ms * 2.23694f;
                printf("Speed = %.2f mph\n", speed_mph);
                break;

            case 3:
                printf("Exiting program\n");
                break;

            default:
                printf("Invalid option\n");
                break;
        }

        if (choice != 3) {
            printf("\nReturning to the menu...\n");
            Sleep(1000);
        }

    } while (choice != 3);

    return 0;
}
