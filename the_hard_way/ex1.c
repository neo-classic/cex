#include <stdio.h>

int main(int argc, char *argv[])
{
    int distance = 100;
    char msg[] = "Hello";
    printf("You are %d miles away!\n", distance);
    printf("%s\n", msg);

    for (int i=0; i<5; i++) {
        printf("%02x ", msg[i]);
    }

    return 0;
}
