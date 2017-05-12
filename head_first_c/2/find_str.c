#include <stdio.h>
#include <string.h>

char tracks[][80] = {
        "Я оставил свое сердце",
        "Ньюарк, ньюарк",
        "Танец с мужланом",
        "Отсюда и до роддома",
        "Девочка с острова Иводзима",
        "Лесник",
        "Охотник"
};

void find_track(char search[]) {
    for(int i = 0; i < 7; i++) {
        if (strstr(tracks[i], search)) {
            printf("#%i. %s\n", i, tracks[i]);
        }
    }
}

int main() {
    char search[80];

    printf("Поиск: ");
    fgets(search, 80, stdin);
    search[strlen(search) - 1] = '\0';

    find_track(search);

    return 0;
}