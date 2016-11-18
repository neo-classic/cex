#include <stdio.h>

int main()
{
    int numerator, denominator, reminder, gcd, orig_n, orig_d;

    printf("Enter a fraction: ");
    scanf("%d/%d", &numerator, &denominator);
    orig_n = numerator;
    orig_d = denominator;

    while(numerator >= 0) {
        reminder = numerator % denominator;
        denominator = numerator;
        numerator = reminder;
        if (numerator == 0) {
            gcd = denominator;
            break;
        }
    }

    printf("In lowest terms: %d/%d\n", orig_n / gcd, orig_d / gcd);
}
