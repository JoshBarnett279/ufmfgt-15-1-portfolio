#include <stdio.h>

double dot_product(int A[], int B[], int size);

int main(void){
    int A[] = {1, 2, 3};
    int B[] = {4, 5, 6};

    int size = sizeof(A) / sizeof(A[0]);

    double result = dot_product(A, B, size);

    printf("The dot product is %.2f\n", result);

    return 0;
}

double dot_product(int A[], int B[], int size){
    double total = 0.0;
    for (int i = 0; i < size; i++){
        total += A[i] * B[i];
    }
    return total;
}