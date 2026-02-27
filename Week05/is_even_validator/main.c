#include <stdio.h>
#include <string.h>

/* Function Prototype */
int is_even(char number[]);

/* Main Function */
int main(void)
{
    char number[1000];   // Can store up to 999 digit number

    printf("Enter a number:\n\n ");
    scanf("%999s", number);

    if (is_even(number))
    {
        printf("Even\n");
    }
    else
    {
        printf("Odd\n");
    }

    return 0;
}

/* Function Definition */
int is_even(char number[])
{
    int length = strlen(number);
    char last_digit = number[length - 1];

    if (last_digit == '0' || last_digit == '2' ||
        last_digit == '4' || last_digit == '6' ||
        last_digit == '8')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}