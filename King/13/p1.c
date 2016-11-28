#include <stdio.h>
#include <string.h>

int main() {
    char s[20], small[20], large[20];

    while (*s != '\n') {
        printf("Enter word: ");
        scanf("%s", &s);
        if (strlen(s) < strlen(small)) {
            strcpy(small, s);
        }
        if (strlen(s) > strlen(large)) {
            strcpy(large, s);
        }
        if (strlen(s) == 4) {
            break;
        }
    }

    printf("Smallest word: %s\n", small);
    printf("Largest word: %s\n", large);
    return 0;
}
