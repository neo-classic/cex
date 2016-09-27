#include <stdio.h>

void main()
{
	long cnt;
	cnt = 0;

	while(getchar() != EOF) {
		++cnt;
	}

	printf("%ld\n", cnt);
}