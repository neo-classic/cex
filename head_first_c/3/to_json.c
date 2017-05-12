#include <stdio.h>

int main() {
    float lat;
    float lng;
    char info[80];
    int started = 0;

    puts("data=[");
    while (scanf("%f,%f,%79[^\n]", &lat, &lng, info) == 3) {
        if (started) {
            printf(",\n");
        } else {
            started = 1;
        }
        if (lat < -90 || lat > 90 || lng < -180 || lng > 180) {
            fprintf(stderr, "Ошибка данных\n");
            return 2;
        }
        printf("{lat: %f, lng: %f, info: '%s'", lat, lng, info);
    }
    puts("\n]");

    return 0;
}