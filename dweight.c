#include <stdio.h>

int main(void) {
int height, length, width, weight, volume;

printf("height :");
scanf("%d", &height);
printf("length :");
scanf("%d", &length);
printf("width :");
scanf("%d", &width);

volume = height * length * width;
weight = (volume + 165) / 166;

printf("Volume is %d\n", volume);
printf("Weight is %d\n", weight);

return 0;
}
