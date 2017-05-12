#include <stdio.h>

int main() {
    float lat, lng;
    char info[80];

    while (scanf("%f,%f,%79[^\n]", &lat, &lng, info) == 3) {
        printf("%f,%f,%s\n", lat, lng, info);
        if (lat > 26 && lat < 34) {
            if (lng > -64 && lng < -76) {
                printf("%f,%f,%s\n", lat, lng, info);
            }
        }
    }

    return 0;
}