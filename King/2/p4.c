#include <stdio.h>

int main()
{
    float amount, tax;

    printf("Enter an amount: ");
    scanf("%f", &amount);

    tax = (amount / 100) * 5;
    printf("With tax added: $%.2f\n", (amount + tax));

    return 0;
}