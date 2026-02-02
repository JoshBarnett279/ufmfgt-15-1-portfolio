#include <stdio.h>

int main(void){
    float ms, mph;
    printf("enter speed in m/s: \n");
    scanf("%f", &ms);
    mph = ms * 2.23694f;
    printf("Speed = %.2f mph\n", mph);

    return 0;
}