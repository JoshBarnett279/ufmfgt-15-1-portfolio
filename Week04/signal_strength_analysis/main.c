#include <stdio.h>

int main() {
    float signals[8] = {88.5, 92.1, 85.0, 95.3, 89.9, 91.2, 84.8, 90.5};
    float min, max, sum = 0.0, average;
    int i;

    min = max = signals[0];

    for (i = 0; i < 8; i++) {
        sum += signals[i];
        if (signals[i] < min) {
            min = signals[i];
        }
        if (signals[i] > max) {
            max = signals[i];
        }
    }

    average = sum / 8.0;

    printf("Minimum Signal Strength: %.2f\n", min);
    printf("Maximum Signal Strength: %.2f\n", max);
    printf("Average Signal Strength: %.2f\n", average);

    return 0;
}
