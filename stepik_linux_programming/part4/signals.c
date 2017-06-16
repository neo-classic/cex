// Подсчет сигналов
//
// Разработать приложение, умеющее обрабатывать сигналы SIGUSR1 ,SIGUSR2, SIGTERM.
// После старта Ваше приложение должно по приходу одного из сигналов SIGUSR1,  SIGUSR2
// выполнять их суммирование, а после прихода сигнала SIGTERM, требуется вывести в стандартный поток вывода 2 числа, разделенных пробелом,
// соответствующих количеству обработанных сигналов SIGUSR1, SIGUSR2, и завершить программу. Вывод оканчивается символом конца строки.

#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

int sigusr1 = 0;
int sigusr2 = 0;

void sigusr1_handler(int signal)
{
    sigusr1++;
}

void sigusr2_handler(int signal)
{
    sigusr2++;
}

void sigterm_handler(int signal)
{
    printf("%d %d\n", sigusr1, sigusr2);
    exit(0);
}

int main(int argc, char *argv[])
{
    signal(SIGUSR1, sigusr1_handler);
    signal(SIGUSR2, sigusr2_handler);
    signal(SIGTERM, sigterm_handler);
    while(1) {

    }

    return 0;
}