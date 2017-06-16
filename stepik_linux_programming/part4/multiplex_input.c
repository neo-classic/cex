// Мультиплексированный ввод
//
// В текущем каталоге есть 2 канала in1 in2, в которые в случайном порядке поступают числа,
// которые необходимо просуммировать и вывести окончательную сумму на экран.
// Сумма выводится в отдельной строке, завершающейся символом конца строки.
// Признаком окончания подачи символов в каналы является закрытие этих каналов посылающей стороной.
//
// Подсказка: для неблокирующего чтения использовать select.
// Замечание: ﻿протокол обмена по каналу текстовый, то есть числа представлены строками

#include <stdio.h>
#include <sys/stat.h>
#include <sys/select.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_LENGTH 200

int read_fifo(int fd, int *sum, fd_set *read_set)
{
    char buf[100];
    int bytes = read(fd, buf, 100);
    buf[bytes] = '\0';
    if (bytes == 0) {
        FD_CLR(fd, read_set);
        close(fd);
        return 0;
    }

    if (strlen(buf)) {
        *sum += atoi(buf);
    } else {
        close(fd);
    }

    return bytes;
}

int main(int argc, char argv[])
{
    int in1 = open("in1", O_RDONLY | O_NONBLOCK);
    int in2 = open("in2", O_RDONLY | O_NONBLOCK);
    int sum = 0, res1 = 0, res2 = 0;
    int i = 0;

    if (!(in1 && in2)) {
        printf("error open fifo\n");
        exit(1);
    }

    fd_set read_set;
    struct timeval tv;
    tv.tv_sec = 4;
    tv.tv_usec = 700000;

    while (true) {
        FD_ZERO(&read_set);
        FD_SET(in1, &read_set);
        FD_SET(in2, &read_set);

        int result = select(in2+1, &read_set, NULL, NULL, &tv);

        if (result) {
            if (FD_ISSET(in1, &read_set)) {
                res1 = read_fifo(in1, &sum, &read_set);
            }
            if (FD_ISSET(in2, &read_set)) {
                res2 = read_fifo(in2, &sum, &read_set);
            }
        }
        i++;

        if (res1 == 0 && res2 == 0) {
            break;
        }
    }

    printf("%d\n", sum);

    return 0;
}