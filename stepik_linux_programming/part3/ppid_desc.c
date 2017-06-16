// Подсчет процессов в поддереве
//
// Разработать программу solution, которая по заданному pid,
// осуществляет поиск всех потомков процесса с этим идентификатором и
// выводит их количество (включая процесс с заданным pid).

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

int cnt = 1;

bool is_int(const char *str);
int get_id(char *filename, const char *needle_str);
void search_for_ppid(int needle_ppid);

int main(int argc, char *argv[])
{
    int needle_ppid;

    if (argc != 2) {
        printf("Введите PID\n");
        exit(1);
    }

    needle_ppid = atoi(argv[1]);

    search_for_ppid(needle_ppid);

    printf("%d\n", cnt);


    return 0;
}

void search_for_ppid(int needle_ppid)
{
    DIR *dir;
    struct dirent *entry;
    char filename[100];

    dir = opendir("/proc");
    if (!dir) {
        perror("diropen");
        exit(1);
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR && is_int(entry->d_name)) {
            strcpy(filename, "/proc/");
            strcat(filename, entry->d_name);
            strcat(filename, "/status");

            int ppid;

            ppid = get_id(filename, "PPid");
            if (ppid == needle_ppid) {
                cnt++;
                search_for_ppid(atoi(entry->d_name));
            }


        }
    }
}

bool is_int(const char *str)
{
   // Handle negative numbers.
   //
   if (*str == '-')
      ++str;

   // Handle empty string or just "-".
   //
   if (!*str)
      return false;

   // Check for non-digit chars in the rest of the stirng.
   //
   while (*str) {
      if (!isdigit(*str))
         return false;
      else
         ++str;
   }

   return true;
}

int get_id(char *filename, const char *needle_str)
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
            istr = strstr(str, needle_str);
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