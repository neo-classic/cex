#include <stdio.h>

int main()
{
    int c;
    int countSpace = 0;
    int countTab = 0;
    int countEOL = 0;

    while((c = getchar()) != EOF) {
        if (c == ' ') {
            ++countSpace;
        } else if (c == '\t') {
            ++countTab;
        } else if (c == '\n') {
            ++countEOL;
        }
    }

    printf("spaces: %d\n", countSpace);
    printf("tabs: %d\n", countTab);
    printf("eol: %d\n", countEOL);

    return 0;
}