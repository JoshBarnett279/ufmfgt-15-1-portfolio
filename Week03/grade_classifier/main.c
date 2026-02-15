#include <stdio.h>

int main(void) {
    int mark;

    printf("Please enter your mark:\n");
    scanf("%d", &mark);
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
