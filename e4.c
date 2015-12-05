#include <stdio.h>

int main(void) {
int input, k, bills;

printf("dollars cout: ");
scanf("%d", &input);
k = input / 20;
printf("$20 - %d\n", k);
input = input - 20 * k;
k = input / 10;
printf("$10 - %d\n", k);
input = input - 10 * k;
k = input / 5;
printf("$5 - %d\n", k);
input = input - 5 * k;
printf("$1 - %d\n", input);

return 0;
}
