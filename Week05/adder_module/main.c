#include <stdio.h>


int add_numbers(int a, int b);

int main(void) {
   int num1, num2;
   int result;

   printf("Enter first number:\n\n");
   scanf("%d", &num1);

   printf("Enter second number:\n\n");
   scanf("%d", &num2);

   result = add_numbers(num1, num2);

   printf("Sum = %d\n ", result);

    return 0;
}

int add_numbers(int a, int b) {
    return a + b;
}
