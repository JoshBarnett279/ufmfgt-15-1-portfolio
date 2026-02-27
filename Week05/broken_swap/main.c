#include <stdio.h>

/* Function Prototype */
void swap(int a, int b);

/* Main Function */
int main(void)
{
    int x = 5;
    int y = 10;

    printf("Before swap: x = %d, y = %d\n", x, y);

    swap(x, y);

    printf("After swap: x = %d, y = %d\n", x, y);

    return 0;
}

/* Function Definition */
void swap(int a, int b)
{
    int temp;

    temp = a;
    a = b;
    b = temp;
}