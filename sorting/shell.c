#include <stdio.h>
#include "common.h"

#define SIZE 7

int array[SIZE] = {4,6,3,2,1,9,7};

void shellSort() {
    int inner, outer, insertion_value;
    int i = 0, interval = 1, elements = SIZE;

    while(interval <= elements/3) {
        interval = interval * 3 + 1;
    }

    while(interval > 0) {
        printf("iteration %d#:",i);
        display(array, SIZE);

        for(outer=interval; outer<elements; outer++) {
            insertion_value = array[outer];
            inner = outer;

            while(inner>interval-1 && array[inner-interval] >= insertion_value) {
                array[inner] = array[inner-interval];
                inner -= interval;
                printf(" item moved :%d\n", array[inner]);
            }

            array[inner] = insertion_value;
            printf(" item inserted :%d, at position :%d\n", insertion_value, inner);
        }

        interval = (interval -1) /3;
        i++;
    }
}

int main() {
    printf("Input Array: ");
    display(array, SIZE);
    shellSort();
    printf("Output Array: ");
    display(array, SIZE);
    return 1;
}
