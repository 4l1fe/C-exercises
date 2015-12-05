#include <stdio.h>

int main(void) {
float input, taxed;

printf("enter: ");
scanf("%f", &input);
taxed = input * 0.05f + input;
printf("%.2f\n", taxed);

return 0;
}
