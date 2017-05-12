#include <stdio.h>

struct exercise {
    const char *description;
    float duration;
};

struct meal {
    const char *ingredients;
    float weight;
};

struct preferences {
    struct meal food;
    struct exercise exercise;
};

struct fish {
    const char *name;
    const char *species;
    int teeth;
    int age;
    struct preferences care;
};

void label(struct fish a)
{
    printf("Кличка: %s\nРазновидность: %s\n%i года, %i зубов\n", a.name, a.species, a.age, a.age);
    printf("Давать %2.2f кг %s и разрешать %s на протяжении %2.2f часов\n", a.care.food.weight, a.care.food.ingredients, a.care.exercise.description, a.care.exercise.duration);
}

int main()
{
    struct fish snappy = {"Зубастик", "пиранья", 69, 4, {{"мясо", 0.09}, {"купаться в джакузи", 7.5}}};
    label(snappy);

}