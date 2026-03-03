#include <stdio.h>

int sum_array(int arr[], int size);

int main(void){
    int numbers[] = {10, 20 ,30, 40, 50};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int total = sum_array(numbers, size);

    printf("Sum of array = %d\n", total);

    return 0;
}

int sum_array(int arr[], int size){
    int total = 0;
    for (int i = 0; i < size; i++){
        total += arr[i];
    }
    return total;
}
