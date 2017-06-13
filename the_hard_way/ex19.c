#include "dbg.h"
#include <stdlib.h>
#include <stdio.h>

void test_debug()
{
    debug("Hello from debug");
    debug("I am %d yo", 28);
}

void test_log_err()
{
    log_err("log_err");
    log_err("qwe %s, %d", "wwww", 212);
}

int test_check(char *filename)
{
    FILE *input = NULL;
    char *block = NULL;

    block = malloc(100);
    check_mem(block);

    input = fopen(filename, "r");
    check(input, "Failed to open %s", filename);

    free(block);
    fclose(input);
    return 0;

error:
    if(block) free(block);
    if(input) fclose(input);
    return -1;
}

int test_sentinel(int code)
{
    char *temp = malloc(100);
    check_mem(temp);

    switch(code) {
        case 1:
            log_info("It worked");
            break;
        default:
            sentinel("I shouldn't run");
    }

    free(temp);
    return 0;

error:
    if(temp) free(temp);
    return -1;
}

int test_check_mem()
{
    char *test = NULL;
    check_mem(test);
    free(test);
    return 1;

error:
    return -1;
}

int test_check_debug()
{
    int i = 0;
    check_debug(i != 0, "Oops, I was 0");
    return 0;

error:
    return -1;
}

int main(int argc, char *argv[])
{
    check(argc == 1, "Need an argument");

    test_debug();
    test_log_err();

    check(test_check("ex19.c") == 0, "failed with ex19.c");
    check(test_check(argv[1]) == -1, "failed with atgv");
    check(test_sentinel(1) == 0, "test_sentinel failed");
    check(test_sentinel(100) == -1, "test_sentinel failed");
    check(test_check_mem() == -1, "test_check_mem failed");
    check(test_check_debug() == -1, "test_check_debug failed");

    return 0;

error:
    return 1;
}