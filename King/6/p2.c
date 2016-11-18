#include <stdio.h>

int main()
{
    int n, m, reminder;
    printf("Enter two numbers: ");
    scanf("%d %d", &n, &m);
    if (n == 0) {
        printf("Greatest common divisor: %d\n", m);
        return 0;
    }
    if (m == 0) {
        printf("Greatest common divisor: %d\n", n);
        return 0;
    }

    while(n >= 0) {
        reminder = m % n;
        m = n;
        n = reminder;
        if (n == 0) {
            printf("Greatest common divisor: %d\n", m);
            return 0;
        }
    }
    
    return 0;
}
