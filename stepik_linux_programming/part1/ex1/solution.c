#include <stdio.h>
#include <string.h>

int stringStat(const char *string, size_t multiplier, int *count)
{
    int len = strlen(string);
    *count+=1;
    return len * multiplier;
}
