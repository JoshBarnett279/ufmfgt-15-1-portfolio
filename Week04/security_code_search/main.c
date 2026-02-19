#include <stdio.h>

int main() {
    int accessCodes[15] = {12, 34, 42, 56, 78, 90, 23, 45, 67, 89, 12, 14, 21, 42, 30};
    int targetCode, i;

    printf("Enter the security code to search for: \n\n");
    scanf("%d", &targetCode);

    for (i = 0; i < 15; i++) {
        if (accessCodes[i] == targetCode) {
            printf("Access Code Found at Position %d\n", i);
            break;
        }
    }

    if (i == 15) {
        printf("Code Not Found\n");
    }

    return 0;
}
