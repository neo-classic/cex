#include <stdio.h>
#define PI 3.1415f

int main()
{
    int r;
    float v;

    scanf("%d", &r);

    v = 4.0f/3.0f * PI * (r*r*r);
    printf("%f\n", v);

    return 0;
}