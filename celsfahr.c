#include <stdio.h>

void main()
{
	float fahr, cels;
	int lower, upper, step;

	lower = -30;
	upper = 45;
	step = 5;

	printf("cels\tfahr\n");

	cels = lower;
	while(cels <= upper) {
		printf("%5.1f\t%5.1f\n", cels, fahr2cels(cels));
		cels = cels + step;
	}
}

float fahr2cels(float cels)
{
	return cels * (9.0/5.0) + 32.0;
}
