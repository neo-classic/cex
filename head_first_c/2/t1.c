#include <stdio.h>

int main()
{
    int arr[] = {1, 2, 3, 5};
    char msg[] = "Test msg";

    int *p = arr;
    char *ch = msg;

    int arr_length = sizeof(arr) / sizeof(int);

    puts("arr = [");
    for(int i=0; i < arr_length; i++) {
        printf(" %i ", arr[i]);
    }
    puts("]\n");

    printf("msg: %s\n", msg);
    printf("&msg: %p\n", &msg);
    puts("======");

    printf("ch: %s\n", ch);
    printf("&ch: %p\n", &ch);
    puts("======");

    printf("arr[0]: %i\n", arr[0]);
    printf("*arr: %i\n", *arr);
    printf("*(arr + 2): %i\n", *(arr + 2));
    printf("2[arr]: %i\n", 2[arr]);
    printf("*(p + 50): %i\n", *(p + 50));
    printf("p + 50: %p\n", p + 50);
    puts("======");

    printf("&arr: %p\n", &arr);
    printf("p: %p\n", p);
    printf("arr: %p\n", arr);
    printf("arr == p == &arr = %p\n", arr);

    return 0;
}