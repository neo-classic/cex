#include <stdio.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    pid_t pid;
    int status;

    switch (pid = fork()) {
        case -1:
            perror("fork\n");
            return -1;
        case 0:
            printf("Выполняется дочерний процесс\n");
            exit(4);
    }

    printf("Выполняется родительский процесс\n");
    printf("Идетификатор дочернего процесса - %d\n", pid);

    if ((pid == waitpid(pid, &status, 0)) && WIFEXITED(status)) {
        printf("Дочерний процесс с PID = %d завершил выполнение\n", pid);
        printf("Код статуса завершения = %d\n", WIFEXITED(status));
    }

    return 0;
}
