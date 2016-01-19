#include <stdio.h>

#define SIZE 10

int array[SIZE] = {4,6,3,2,1,9,7,3,11,77};

void printline(int count) {
    int i;

    for (i=0; i<count-1; i++) {
        printf("=");
    }
    printf("\n");
}

void display() {
    int i;

    for (i=0; i<SIZE; i++) {
        printf("%d", array[i]);
    }
    printf("\n");
}

void isertionSort() {
    int i, value, position;

    for (i=1; i<SIZE; i++) {
        value = array[i];
        position = i;

        while (position > 0 && array[position-1] > value) {
            array[position] = array[position-1];
            position--;
            printf(" item moved : %d\n" , array[position]);
        }
        if (position != i) {
            printf(" item inserted : %d, at position : %d\n" , value, position);
            array[position] = value;
        }
        printf("Iteration %d#:", i);
        display();
    }
}

void main() {
    printf("Input:");
    display();
    printline(50);
    isertionSort();
    printf("Output:");
    display();
    printline(50);
}
