#include <stdio.h>

void swap(void *a, void *b, void *tmp, size_t bytes);

int main()
{
    int a = 5;
    int b = 6;
    int tmp;
    swap(&a, &b, &tmp, sizeof(int));
    printf("a = %i\n", a);
    printf("b = %i\n", b);
    return 0;
}

void swap(void *a, void *b, void *tmp, size_t bytes)
{
    memcpy(tmp, a, bytes);
    memcpy(a, b, bytes);
    memcpy(b, tmp, bytes);
}