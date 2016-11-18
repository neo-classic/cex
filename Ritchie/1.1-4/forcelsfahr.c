#include <stdio.h>

#define	LOWER	-30.0
#define	UPPER	50.0
#define	STEP	 5

void main()
{
	float cels;

	for (cels = LOWER; cels <= UPPER; cels = cels + STEP) {
		printf("%4.1f %5.1f\n", cels, (cels * (9.0 / 5.0) + 32.0));
	}
}