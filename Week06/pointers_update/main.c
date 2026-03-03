#include <stdio.h>
#include <stdlib.h>


void foo1(int xval){
    int x;
    x = xval;
    printf("The address of x is %p\n\n", (void*)&x);
}
void foo2(int yval){
    int y;
    y = yval;
    printf("The address of y is %p\n\n", (void*)&y);
}
void foo3(int zval){
    int z;
    z = zval;
    printf("The address of z is %p\n\n", (void*)&z);
}
int main(void){
    foo1(7);
    foo2(11);
    foo3(16);
    system("PAUSE");
    return 0;
}