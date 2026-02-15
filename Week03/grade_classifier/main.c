#include <stdio.h>

int main(void) {
    int mark;

    do {
        printf("Please enter your mark (0-100):\n\n ");
        scanf("%d", &mark);

        if (mark < 0 || mark > 100) {
            printf("Invalid mark, try again.\n");
        }
    } while (mark < 0 || mark > 100);
    if (mark < 0 ||  mark > 100){
        printf("Invalid\n");
    }
    else if (mark < 40){
        printf("Fail\n");
    }
    else if (mark < 60) {
        printf("Pass\n");
    }
    else if (mark < 70){
        printf("Merit\n");
    }
    else {
        printf("Distinction\n");
    }
    return 0;
}
