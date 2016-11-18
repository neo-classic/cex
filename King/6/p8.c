#include <stdio.h>

int main() {
    int n, day;

    printf("Enter number of days in month: ");
    scanf("%d", &n);

    printf("Enter starting day of the week (1=пн 7=вс): ");
    scanf("%d", &day);

    printf(" пн вт ср чт пт сб вс\n");

    for (int i=1; i<day; i++) {
        printf("   ");
    }
    for (int i=1; i<=n; i++) {
        printf("%3d", i);
        if (day % 7 == 0) {
            printf("\n");
        }
        ++day;
    }
    printf("\n");

    return 0;
}
