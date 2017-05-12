#include <stdio.h>

int main()
{
    int c;
    int isSpace = 0;

    while((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n') {
            ++isSpace;
        } else if (c != '\n') {
            isSpace = 0;
        }

        if (isSpace == 1) {
            printf("\n");
        } else if (isSpace == 0) {
            putchar(c);
        }

    }
    return 0;
}