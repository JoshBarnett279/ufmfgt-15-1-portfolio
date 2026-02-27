#include <stdio.h>

void print_welcome_message(void);

int main(void){
    print_welcome_message();
    return 0;
}

void print_welcome_message(void) {
    printf("***************************************\n");
    printf("*     ENGINEERING CALCULATOR v1.0     *\n");
    printf("*    System Ready. Awaiting Input.    *\n");
    printf("***************************************\n");
}