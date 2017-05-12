#include <stdio.h>

int main()
{
    int c;
    int spaceCount = 0;

    while((c = getchar()) != EOF) {
        if (c == ' ') {
            ++spaceCount;
        } else {
            spaceCount = 0;
        }

        if (spaceCount == 1 || c != ' ') {
            putchar(c);
        }
    }

    return 0;
}