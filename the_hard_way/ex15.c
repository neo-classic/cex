#include <stdio.h>

int main(int argc, char *argv[])
{
    int ages[] = {23, 25, 11, 78, 55};
    char *names[] = {"Alan", "Ann", "Yuriy", "Mary", "Vasya"};

    int count = sizeof(ages) / sizeof(int);
    int i = 0;

    for (i = 0; i < count; i++) {
        printf("%s = %d\n", names[i], ages[i]);
    }

    printf("----\n");

    int *cur_age = ages;
    char **cur_name = names;

    for (i = 0; i < count; i++) {
        printf("%s = %d\n", cur_name[i], cur_age[i]);
    }

    printf("----\n");

    for (i = 0; i < count; i++) {
        printf("%s = %d\n", *(cur_name+i), *(cur_age+i));
    }

    printf("----\n");

    return 0;
}
