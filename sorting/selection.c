#include <stdio.h>
#include "common.h"

#define SIZE 7

int array[SIZE] = {4,6,3,2,1,9,7};

void selectionSort() {
    int i, j, min, tmp;

    for (i=0; i<SIZE-1; i++) {
        min = i;

        for (j=i+1; j<SIZE; j++) {
            if (array[j] < array[min]) {
                min = j;
            }
        }
        if (i != min) {
            printf("Items swapped: [ %d, %d ]\n" , array[i], array[min]);
            tmp = array[i];
            array[i] = array[min];
            array[min] = tmp;
        }
        printf("Iteration %d#:",(i+1));
        display(array, SIZE);
        printf("\n");
    }
}

void main() {
    printf("Input: ");
    display(array, SIZE);
    printf("\n");
    selectionSort();
    printf("Output: ");
    display(array, SIZE);
}
