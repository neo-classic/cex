#include <stdio.h>

int main()
{
    int i, *ptr;

    i = 20;
    ptr = &i;

    printf("%d\n", i);
    printf("%d\n", &i);
    printf("%d\n", *ptr);
    printf("%d\n", ptr);

    return 0;
}
