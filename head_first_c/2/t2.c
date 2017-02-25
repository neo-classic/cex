#include <stdio.h>

int main()
{
    char first_name[20];
    char last_name[20];

    printf("Введите Имя и Фамилию: ");
    scanf("%19s %19s", first_name, last_name);
    printf("Вы ввели: %s %s\n", last_name, first_name);

    return 0;
}