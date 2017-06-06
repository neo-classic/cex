#include <stdio.h>

int main(void)
{
    int arr[100] = {0};
    int num = 0;
    float sum = 0;

    printf("Введите кол-во элементов: ");
    scanf("%d", &num);

    while (num < 1 || num > 100) {
        printf("Кол-во должно быть от 1 до 100\n");
        printf("Введите кол-во элементов: ");
        scanf("%d", &num);
    }

    for (int i = 0; i < num; i++) {
        printf("Введите arr[%d] = ", i);
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    int greatest = arr[1];
    for (int i = 0; i < num-1; i++) {
        if (arr[i] < arr[i+1]) {
            greatest = arr[i+1];
        }
    }

    printf("Avg = %.2f\n", (sum / num));
    printf("greatest = %d\n", greatest);


    return 0;
}
