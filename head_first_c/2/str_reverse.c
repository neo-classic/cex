#include <stdio.h>
#include <string.h>

void str_reverse(char *str) {
    size_t len = strlen(str);
    char *t = str + len - 1;

    while (t >= str) {
        printf("%c", *t);
        t -= 1;
    }

    puts("");
}

int main() {
    char str[] = "Yuriy Belyakov";

    str_reverse(str);

    return 0;
}