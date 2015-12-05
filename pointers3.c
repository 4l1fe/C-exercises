#include <stdio.h>

int main(int argc, char **argv) {
    char str1[] = "Hello";
    char *str2 = "Goodbye";
    printf("%p %p %s\n", &str1, str1, str1);
    printf("%c[%u] - %p\n", str1[0], str1[0], &str1[0]);    
    printf("%c[%u] - %p\n", str1[1], str1[1], &str1[1]);    
    printf("%c[%u] - %p\n", str1[2], str1[2], &str1[2]);    
    printf("%c[%u] - %p\n", str1[3], str1[3], &str1[3]);    
    printf("%c[%u] - %p\n", str1[4], str1[4], &str1[4]);    
    printf("%c[%u] - %p\n", str1[5], str1[5], &str1[5]);    

    printf("\n%p %p %s\n", &str2, str2, str2);
    printf("%c[%u] - %p\n", str2[0], str2[0], &str2[0]);    
    printf("%c[%u] - %p\n", str2[1], str2[1], &str2[1]);    
    printf("%c[%u] - %p\n", str2[2], str2[2], &str2[2]);    
    printf("%c[%u] - %p\n", str2[3], str2[3], &str2[3]);    
    printf("%c[%u] - %p\n", str2[4], str2[4], &str2[4]);
    printf("%c[%u] - %p\n", str2[5], str2[5], &str2[5]);    
    return 0;
}
