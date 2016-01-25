#include <stdio.h>
#include "common.h"

#define SIZE 8

int array[SIZE] = {35,33,42,10,14,19,27,44};

void shellSort() {
    int left, right, insertion_value;
    int step = 0, interval = 1;

    while(interval <= SIZE/3) {
        interval = interval * 3 + 1;
    }

    while(interval > 0) {
        printf("iteration %d#:",step);
        display(array, SIZE);

        for(right=interval; right<SIZE; right++) {
            insertion_value = array[right];
            left = right;

            while(left>interval-1 && array[left-interval] >= insertion_value) {
                array[left] = array[left-interval];
                left -= interval;
                printf(" item moved :%d\n", array[left]);
            }

            array[left] = insertion_value;
            printf(" item inserted :%d, at position :%d\n", insertion_value, left);
        }

        interval = (interval -1) /3;
        step++;
    }
}

void main() {
    printf("Input Array: ");
    display(array, SIZE);
    shellSort();
    printf("Output Array: ");
    display(array, SIZE);
}
