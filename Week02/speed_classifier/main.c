#include <stdio.h>

int main(void) {
    float speed;
    printf("Please enter speed in mph:\n");
    scanf("%f", &speed);
    if (speed > 70) {
        printf("Speeding\n");
    } else if (speed >= 30) {
        printf("Normal\n");
    } else {
        printf("Slow\n");
    }

    return 0;
}
