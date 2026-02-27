#include <stdio.h>

/* Function Prototype */
int power(int base, int exponent);

/* Main Function */
int main(void)
{
    int base;
    int exponent;
    int result;

    printf("Enter base: \n\n");
    scanf("%d", &base);

    printf("Enter exponent (positive integer):\n\n ");
    scanf("%d", &exponent);

    if (exponent < 0) {
        printf("Exponent must be positive\n\n");
        return 1;
    }

    result = power(base, exponent);

    printf("%d^%d = %d\n\n", base, exponent, result);

    return 0;
}

/* Function Definition */
int power(int base, int exponent)
{
    int result = 1;
    int i;

    for (i = 0; i < exponent; i++)
    {
        result = result * base;
    }

    return result;
}