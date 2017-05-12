#include <stdio.h>

#define IN_WORD 1
#define OUT_WORD 0
#define MAX_WORD_LENGTH 10

int main()
{
    int lengthWords[MAX_WORD_LENGTH];
    int lWord, state, c;
    int totalSymbols = 0;
    int totalWords = 0;

    for (int i = 0; i < MAX_WORD_LENGTH; i++) {
        lengthWords[i] = 0;
    }

    lWord = state = OUT_WORD;

    while((c = getchar()) != EOF) {
        ++totalSymbols;

        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT_WORD;
            if (lWord < MAX_WORD_LENGTH) {
                ++lengthWords[lWord];
                lWord = 0;
            }
        } else if (state == OUT_WORD) {
            state = IN_WORD;
            ++totalWords;
        }

        if (state == IN_WORD) {
            ++lWord;
        }
    }
    ++lengthWords[lWord];

    for (int j = 10; j >= 1; j--) {
        printf("%2d: ", j);
        for (int i = 0; i < MAX_WORD_LENGTH; ++i) {
            if ((j - lengthWords[i]) > 0) {
                printf("   ");
            } else {
                printf(" x ");
            }
        }
        putchar('\n');
    }

    printf("    ");
    for (int i = 0; i < MAX_WORD_LENGTH; ++i) {
        printf(" %d ", i);
    }

    putchar('\n');
    printf("Всего символов: %d\n", totalSymbols);
    printf("Всего слов: %d\n", totalWords);

    return 0;
}