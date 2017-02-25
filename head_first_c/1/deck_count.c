#include <stdio.h>

int main() {
    int decks;
    puts("Введите количество колод: ");
    scanf("%i", &decks);
    
    if (decks < 1) {
        puts("Вы ввели недопустимое количество колод!");
        return 1;
    }
    
    printf("Всего карт: %i\n", (decks * 52));
    
    return 0;
}
