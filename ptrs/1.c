#include <stdio.h>

int main()
{
    int a = 147;
    int *ptr_a = &a;
    printf("*ptr_a = %i\n", *ptr_a);
    printf("address of ptr_a = %p\n", ptr_a);
    printf("address of a(&a) = %p\n", &a);
    return 0;
}