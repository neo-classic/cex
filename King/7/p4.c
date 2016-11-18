#include <stdio.h>

int main() {
    char ch;
    printf("Enter phone number: ");
    while((ch = getchar()) != '\n') {
        if (ch == '-'){
            printf("-");
            continue;
        }

        if (ch >= '0' && ch <= '9') {
            printf("%c", ch);
        } else {
            if (ch == 'A' || ch == 'B' || ch == 'C') {
                printf("2");
                continue;
            } else if (ch == 'D' || ch == 'E' || ch == 'F') {
                printf("3");
                continue;
            } else if (ch == 'G' || ch == 'H' || ch == 'I') {
                printf("4");
                continue;
            } else if (ch == 'J' || ch == 'K' || ch == 'L') {
                printf("5");
                continue;
            } else if (ch == 'M' || ch == 'N' || ch == 'O') {
                printf("6"); continue;
            } else if (ch == 'P' || ch == 'R' || ch == 'S') {
                printf("7"); continue;
            } else if (ch == 'T' || ch == 'U' || ch == 'V') {
                printf("8"); continue;
            } else if (ch == 'W' || ch == 'X' || ch == 'Y') {
                printf("9"); continue;
            }
        }
    }
    printf("\n");
    return 0;
}
