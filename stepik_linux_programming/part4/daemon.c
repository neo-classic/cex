// "Правильный" демон
//
// В задании требуется доработать демон, разработанный ранее в задании 6 модуля 3.5.
// Задача -- снабдить демон обработчиком сигнала SIGURG, по приходу которого демон должен завершать свою работу.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>

void sigurg_handler(int signal)
{
    exit(0);
}

int main(int argc, char *argv[])
{
    int pid = fork();
    switch (pid) {
        case 0:
            setsid();
            chdir("/");
            printf("%d\n", getpid());
            close(stdin);
            close(stdout);
            close(stderr);
            signal(SIGURG, sigurg_handler);
            while(1) {};
        case -1:
            printf("Fail: unable to fork");
            break;
    }

    return 0;
}