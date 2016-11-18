#include <stdio.h>

int main()
{
    int n, n1, n2, n3;
    printf("Enter a three-digit number: ");
    scanf("%d", &n);
    n3 = n/100;
    n1 = (n-(100*n3))%10;
    n2 = (n-(100*n3))/10;
    printf("The reversal is: %d%d%d\n", n1, n2, n3);
    return 0;
}
