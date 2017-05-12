#include <stdio.h>

typedef struct {
    char *name;
    char *opens;
    char *closes;
    struct island *next;
} island;

void display(island *start);

int main()
{
    island amity = {"Дружба", "09:00", "17:00", NULL};
    island craggy = {"Скалистый", "09:00", "17:00", NULL};
    island isla_nublar = {"Туманный", "09:00", "17:00", NULL};
    island shutter = {"Проклятых", "09:00", "17:00", NULL};
    island skull = {"остров Черепа", "09:00", "17:00", NULL};

    amity.next = &craggy;
    craggy.next = &isla_nublar;
    isla_nublar.next = &skull;
    skull.next = &shutter;

    display(&amity);

    return 0;
}

void display(island *start)
{
    island *i = start;
    for(; i != NULL; i = i->next) {
        printf("Название: %s открыт: %s-%s\n", i->name, i->opens, i->closes);
    }
}