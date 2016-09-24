#include <stdio.h>

void main()
{
	float fahr, cels;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 10;

	fahr = lower;
	printf("fahr\tcels\n");

	while(fahr <= upper) {
		cels = (5.0 / 9.0) * (fahr - 32);
		printf("%4.1f\t%4.1f\n", fahr, cels);
		fahr = fahr + step;
	}
}