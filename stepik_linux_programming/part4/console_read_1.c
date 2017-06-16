// Чтение консольного вывода
//
// Некоторая утилита генерирует довольно большой вывод, а вам требуется всего-лишь
// посчитать количество символов '0' в этом выводе.
// Утилита при запуске принимает 1 параметр. Вам требуется разработать программу,
// которая вызывает указанную утилиту, с заданным параметром и подсчитывает количество символов '0' в ее выводе.
// Ваша программа принимает на вход 2 параметра -- имя утилиты, в текущем каталоге и ее параметр.
// Ваша программа должна после подсчета вывести найденное число '0' в отдельной строке, заканчивающейся символом конца строки.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc < 3) {
        printf("Usage: ./solution someprog param\n");
        exit(1);
    }

    FILE *fd;
    char output[4096];
    int cnt = 0;
    char cmd[1024];

    strcpy(cmd, argv[1]);
    strcat(cmd, " ");
    strcat(cmd, argv[2]);

    fd = popen(cmd, "r");
    if (fd == NULL) {
        printf("Failed to exec\n");
        exit(1);
    }

    while (fgets(output, sizeof(output) - 1, fd) != NULL) {
        int i = 0;
        for (i = 0; i < strlen(output); i++) {
            if (output[i] == '0') {
                cnt++;
            }
        }
    }

    pclose(fd);

    printf("%d\n", cnt);


    return 0;
}