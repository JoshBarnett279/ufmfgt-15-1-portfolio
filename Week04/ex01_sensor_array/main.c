#include <stdio.h>

#define SIZE 10

int main(void) {

    double sensors[SIZE];
    int i;

    for (i = 0; i < SIZE; i++) {
        sensors[i] = -1.0;
    }

    for (i = 0; i < SIZE; i++) {
        printf("Sensor %d = %.1f\n", i, sensors[i]);
    }

    return 0;
}
