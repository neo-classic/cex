#include <stdio.h>

void go_south_east(int* lat, int* lng)
{
    *lat -= 1;
    *lng += 1;
}

int main()
{
    int lat = 32;
    int lng = -64;

    go_south_east(&lat, &lng);

    printf("Стоп! Теперь наши координаты: [%i, %i]\n", lat, lng);

    return 0;
}