#include <stdio.h>

int power(int i, int j);

void main()
{
	int i;
	for(i = 1; i <= 10; i++) {
		printf("%2d %4d %5d\n", i, power(2, i), power(3, i));
	}
}

int power(int base, int n)
{
	int res = 1;

	for(res=1; n > 0; --n) {
		res *= base;
	}

	return res;
}
