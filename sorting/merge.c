#include <stdio.h>

// #define SIZE 10
#define SIZE 4

int temp[SIZE];
//int array[SIZE] = { 10, 14, 19, 26, 27, 31, 33, 35, 42, 44 };
int array[SIZE] = { 10, 14, 19, 26 };

void merging (int low, int mid, int high) {
    int n1, n2, i;

    for (n1=low, n2=mid+1, i=low; n1<=mid && n2<=high; i++) {
        if(array[n1] <= array[n2])
            temp[i] = array[n1++];
        else
            temp[i] = array[n2++];
    }
    while (n1 <= mid) {
        temp[i++] = array[n1++];
    }
    while (n2 <= high) {
        temp[i++] = array[n2++];
    }
    for (i=low; i<=high; i++) {
        array[i] = temp[i];
    }
}

void sort(int low, int high) {
    int mid;

    if (low < high) {
        mid = (low + high) / 2;
        sort(low, mid);
        sort(mid+1, high);
        merging(low, mid, high);
    }
    else {
        return;
    }

}

void main() {
    int i;

    printf("Array before sorting\n");
    sort(0, SIZE);
    for (i=0; i<=SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n\nArray after sorting\n");
    for (i=0; i<=SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
