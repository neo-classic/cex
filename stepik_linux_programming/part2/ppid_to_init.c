#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

int getPpid(char *filename)
{
    char str[100];
    char *istr;
    char *token;

    FILE *fd = fopen(filename, "r");
    if (fd == NULL) {
        printf("Ошибка открытия файла\n");
        exit(1);
    }

    while (!feof(fd)) {
        if (fgets(str, sizeof(str), fd)) {
            istr = strstr(str, "PPid");
            if (istr != NULL) {
                token = strtok(str, "\t");
                int i = 0;
                while (token != NULL) {
                    if (i == 1) {
                        fclose(fd);
                        return atoi(token);
                    }
                    token = strtok(NULL, "\t");
                    i++;
                }
            }
        }
    }
}

void llog(const char *message)
{
    printf("//%s\n", message);
}

int main(int argc, char *argv[])
{
    printf("%s\n", argv[1]);

    char filename[100] = "/proc/";
    strcat(filename, argv[1]);
    strcat(filename, "/status");

    int ppid;

    ppid = getPpid(filename);

    while(ppid != 1) {
        printf("%d\n", ppid);

        char cPpid[32];
        sprintf(cPpid, "%d", ppid);

        strcpy(filename, "/proc/");
        strcat(filename, cPpid);
        strcat(filename, "/status");
        ppid = getPpid(filename);
    }

    printf("1\n");

    return 0;
}