#include <stdio.h>

int main(void) {
    float speed;
    printf("Enter speed in mph\n");
    scanf("%f", &speed);
    if (speed < 0) {
        printf("Invalid speed\n");
    }else if (speed > 70) {
            printf("Speeding\n");
    } else {
        printf("Valid speed\n");
    }
    return 0;
}
