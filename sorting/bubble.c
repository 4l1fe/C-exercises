#include <stdio.h>
#include <stdbool.h>
#include "common.h"

#define SIZE 20

int array[SIZE] = {19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

void bubbleSort() {
    int i, j, tmp;
    bool swapped = false;

    for (i=0; i<SIZE-1; i++) {
        swapped = false;

        for (j=0; j<SIZE-1-i; j++) {
            if (array[j] > array[j+1]) {
                tmp = array[j];
                array[j] = array[j+1];
                array[j+1] = tmp;

            swapped = true;
            printf(" => swapped [%d, %d]\n", array[j], array[j+1]);
            }
        }
        if (!swapped) {
            break;
        }
        printf("Iteration: ");
        display(array, SIZE);
        printf("\n");
    }
}

void main() {
    printf("Input:");
    display(array, SIZE);
    printf("\n");

    bubbleSort();
    printf("sorted:");
    display(array, SIZE);
    printf("\n");
}
