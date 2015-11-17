#include <stdio.h>

#define N 10

void max_min(int a[], int n, int *max, int *min);

int main() {
    int b[N], i, biggest, smallest;
    
    printf("Enter %d numbers: ", N);
    for (i=0; i<N; i++)
        scanf("%d", &b[i]);
    
    max_min(b, N, &biggest, &smallest);

    printf("Biggest is %d\n", biggest);
    printf("Smallest is %d\n", smallest);

    return 0;
}

void max_min(int a[], int n, int *max, int *min) {
    int i;

    *max = *min = a[0];
    for (i=1;i<N;i++) {
        if (a[i]>*max)
            *max = a[i];
        else if(a[i] <*min)
            *min = a[i];
    }
}


