#include <stdio.h>

int main(int argc, char const *argv[]) {
    int i;
    for (i = argc-1; i > 0; i--) {
        printf("%s ", argv[i]);
    }
    return 0;
}
