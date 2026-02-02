#include <stdio.h>

int main(void) {
    float speed;
    printf("Enter speed in mph:\n");
    scanf("%f", &speed);

    if (speed > 70) {
        printf("Speeding\n");
    } else {
        printf("Within limit\n");
    }
    return 0;
}