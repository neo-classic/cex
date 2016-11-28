#include <stdio.h>

int main(int argc, char const *argv[]) {
    int sum = 0;
    for (int i = 1; i < argc; i++) {
        sum = sum + atoi(argv[i]);
    }
    printf("Total: %d\n", sum);
    return 0;
}
