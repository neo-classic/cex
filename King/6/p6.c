#include <stdio.h>

int main() {
    int n, sqr;

    printf("Enter a number: ");
    scanf("%d", &n);

    for (int i=2; i <= n; i+=2) {
        sqr = i * i;
        if (sqr >= n) {
            return 0;
        }

        printf("%d\n", sqr);
    }
    return 0;
}
