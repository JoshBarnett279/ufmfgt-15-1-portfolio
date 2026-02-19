#include <stdio.h>

int main() {
    int statusCodes[12] = {1, 5, -2, 0, 8, -1, 0, 0, 9, -4, 2, 1};
    int positiveCount = 0, negativeCount = 0, zeroCount = 0;
    int i;

    for (i = 0; i < 12; i++) {
        if (statusCodes[i] > 0) {
            positiveCount++;
        } else if (statusCodes[i] < 0) {
            negativeCount++;
        } else {
            zeroCount++;
        }
    }

    printf("Positive Codes: %d\n", positiveCount);
    printf("Negative Codes: %d\n", negativeCount);
    printf("Zero Codes: %d\n", zeroCount);

    return 0;
}
