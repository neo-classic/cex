#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

bool is_int(const char *str);

int main()
{
    DIR *dir;
    struct dirent *entry;
    char *istr, *ret;
    char *token;
    char str[100];
    char filename[100];
    int i = 0;

    dir = opendir("/proc");
    if (!dir) {
        perror("diropen");
        exit(1);
    };

    while ( (entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR && is_int(entry->d_name)) {

            strcpy(filename, "/proc/");
            //strcat(filename, "/proc/");
            strcat(filename, entry->d_name);
            strcat(filename, "/status");

            FILE *fd = fopen(filename, "r");

            while (!feof(fd)) {
                if (fgets(str, sizeof(str), fd)) {
                    istr = strstr(str, "Name");
                    if (istr != NULL) {
                        token = strtok(str, "\t");
                        int iTmp = 0;
                        while (token != NULL) {
                            if (iTmp == 1) {
                                ret = strstr(token, "genenv");
                                if (ret != NULL) {
                                    printf("%s", token);
                                    i++;
                                }
                            }
                            token = strtok(NULL, "\t");
                            iTmp++;
                        }
                    }
                }
            }

            fclose(fd);
        }
    };

    closedir(dir);

    printf("%d\n", i);

    return 0;
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
   while (*str)
   {
      if (!isdigit(*str))
         return false;
      else
         ++str;
   }

   return true;
}