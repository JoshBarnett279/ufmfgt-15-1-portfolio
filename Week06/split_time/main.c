#include <stdio.h>

void split_time(long total_sec, int *hr, int *min, int *sec);

int main(void){
    long total_sec;
    int hours, mins, secs;

    printf("Enter total seconds:\n\n");
    scanf("%ld", &total_sec);

    split_time(total_sec, &hours, &mins, &secs);
    printf("Time taken: \n%d hrs\n%d mins\n%d secs\n", hours, mins, secs);

    return 0;
}

void split_time(long total_sec, int *hr, int *min, int *sec){
    *hr = total_sec / 3600;
    long remaining = total_sec % 3600;
    *min = remaining / 60;
    *sec = remaining %60;
}
