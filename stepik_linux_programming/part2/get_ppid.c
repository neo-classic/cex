// Поиск ppid c использованием procfs
//
// Разработать программу solution, которая осуществляет поиск
// родительского PID текущего процесса в файловой системе proc
// и выводит найденное значение на консоль.
// Результат, возвращаемый функций должен быть выведен отдельной строкой
// (должен оканчиваться символом перевода строки \n) в stdio.

#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fd;
    char str[100];
    char *istr;
    char *token;

    fd = fopen("/proc/self/status", "r");
    if (fd == NULL) {
        printf("Ошибка открытия файла\n");
        return 1;
    }

    while (!feof(fd)) {
        if (fgets(str, sizeof(str), fd)) {
            istr = strstr(str, "PPid");
            if (istr != NULL) {
                token = strtok(str, "\t");
                int i = 0;
                while (token != NULL) {
                    if (i == 1) {
                        printf("%s", token);
                    }
                    token = strtok(NULL, "\t");
                    i++;
                }
            }
        }
    }

    return 0;
}
