#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <glob.h>
#include "dbg.h"

#define MAX_LINE 1024

char **parse_argv(int argc, char *argv[], int *or_flag, int *search_words_cnt)
{
    char **search_words = NULL;

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            *or_flag = 1;
            continue;
        } else {
            search_words = (char **)realloc(search_words, ((*search_words_cnt) + 1) * sizeof(char *));
            search_words[(*search_words_cnt)++] = strdup(argv[i]);
        }
    }

    return search_words;
}

void free_mem(char *search_words[], int *search_words_cnt)
{
    for (int i = 0; i < *search_words_cnt; i++) {
        free(search_words[i]);
    }
    free(search_words);
}

int file_list(glob_t *globbuf)
{
    int rc = -1;
    rc = glob("*.h", GLOB_TILDE, NULL, globbuf);
    check(rc == 0, "Faild to load .h");
    rc = glob("*.c", GLOB_TILDE | GLOB_APPEND, NULL, globbuf);
    check(rc == 0, "Faild to load .c");

    rc = 0;
error:
    return rc;
}

int scan_files(const char *filename, int *search_words_cnt, char **search_words, int *or_flag)
{
    char *line = calloc(MAX_LINE, 1);
    FILE *fd = fopen(filename, "r");
    char *found = NULL;
    int i = 0;

    check(fd, "File not found: %s", filename);
    check_mem(line);

    while (fgets(line, MAX_LINE-1, fd) != NULL && found == NULL) {
        int found_cnt = 0;
        for (i = 0; i < *search_words_cnt; i++) {
            found = strcasestr(line, search_words[i]);
            if (found) {
                found_cnt++;
                if (!*or_flag && found_cnt == 1) {
                    printf("%s \t %s", filename, line);
                }
            }
        }

        if (*or_flag && found_cnt == *search_words_cnt) {
            printf("%s \t %s", filename, line);
        }
    }

    free(line);
    fclose(fd);
    return 0;
error:
    if (line) free(line);
    if (fd) fclose(fd);
    return -1;
}

int main(int argc, char *argv[])
{
    check(argc > 1, "Usage: ./logfind [-o] word word ...")

    int or_flag = 0;
    char **search_words = NULL;
    int search_words_cnt = 0;
    glob_t globbuf;

    search_words = parse_argv(argc, argv, &or_flag, &search_words_cnt);

    file_list(&globbuf);

    for (int i = 0; i < globbuf.gl_pathc; i++) {
        scan_files(globbuf.gl_pathv[i], &search_words_cnt, search_words, &or_flag);
    }

    globfree(&globbuf);
    free_mem(search_words, &search_words_cnt);

    return 0;
error:
    free_mem(search_words, &search_words_cnt);
    return 1;
}