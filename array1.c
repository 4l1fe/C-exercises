#include <stdio.h>
#define N 10

int main(void) {

int a[N], i, b[]={1, [2]=77, [3]=13, 4, [5]=5};

printf("Enter %d numbers: ", N);
for (i=0;i<N;i++)
  scanf("%d", &a[i]);

printf("In reverse order: ");
for (i=N-1 ;i>=0; i--)
  printf("%d ", a[i]);

printf("\n");

for (i=0; i< (int) sizeof(b)/sizeof(b[0]); i++)
  printf("%d ", b[i]);

printf("\n");

return 0;
}
