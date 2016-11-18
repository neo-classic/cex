#include <stdio.h>

int main()
{
    int x;
    printf("Please input x: ");
    scanf("%d", &x);

    printf("If x=%d, then polunomial=%d\n", x, ((3*x*x*x*x*x) + (2*x*x*x*x) - (5*x*x*x) - (x*x) + (7*x) - 6));
    return 0;
}