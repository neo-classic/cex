#include <stdio.h>

int exp(int x, int n);

int main()
{
    int x = 0;
    int n = 0;
    int res = 0;

    printf("x = ");
    scanf("%i", &x);
    printf("n = ");
    scanf("%i", &n);

    if (n == 0) {
        res = 1;
    } else if (n % 2 == 0) {
        res = exp(x, n);
    } else if (n % 2 == 1) {
        res = x * exp(x, n);
    }

    return 0;

}

int exp(int x, int n)
{
    return
}