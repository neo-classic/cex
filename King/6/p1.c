#include <stdio.h>

int main()
{
    float max = 0.0f, num;
    for(;;) {
        printf("Enter a number: ");
        scanf("%f", &num);

        if (num == 0) {
            printf("The largest number was: %.2f\n", max);
            return 0;
        } else {
            if (num > max) {
                max = num;
            }
        }
    }
}
