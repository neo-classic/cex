#include <stdio.h>

int main() {
    char name[20];
    puts("Введите имя Вашей девушки: ");
    scanf("%19s", name);
    printf("Дорогая %s. \n\n\tС тобой покончено!\n", name);
    printf("Адрес в памяти: %p\n", &name);

    return 0;
}
