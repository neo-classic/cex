// Создание демона
//
// Разработать программу solution, которая при запуске себя "демонизирует" и остается в  памяти.
// Перед закрытием стандартного потока вывода stdout унаследованного от родителя,
// программа должна вывести в него Pid процесса-демона.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

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
            sleep(10);
            exit(0);
        case -1:
            printf("Fail: unable to fork");
            break;
    }

    return 0;
}