#include "solution.c"

int main()
{
    char *ch = "yuriy";
    int cnt = 8;

    int res = stringStat(ch, 5, &cnt);
    printf("res is %d and cnt is %d\n", res, cnt);

    return 0;
}
