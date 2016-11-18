#include <stdio.h>

int main()
{
    int amount = 0, twenty = 0, ten = 0, five = 0, one = 0;

    printf("Enter a dollar amount: ");
    scanf("%d", &amount);

    twenty = amount / 20;
    ten = (amount - 20 * twenty) / 10;
    five = (amount - (20 * twenty + 10 * ten)) / 5;
    one = amount - (20 * twenty + 10 * ten + 5 * five);
    printf("$20 bills: %d\n", twenty);
    printf("$10 bills: %d\n", ten);
    printf("$5 bills: %d\n", five);
    printf("$1 bills: %d\n", one);
    return 0;
}