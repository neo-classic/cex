#include <stdio.h>

int main()
{
    int c, sflag;

    sflag = 0;
    while ((c = getchar()) != EOF){
        if (c != ' '){
            putchar(c);
            sflag = 0;
        }
        else if (sflag == 0){
            putchar(c);
            sflag = 1;
        }
    }
    return 0;
}