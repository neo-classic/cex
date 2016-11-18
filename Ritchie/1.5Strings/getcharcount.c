#include <stdio.h>

int main(void)
{
	int sc, tc, nc;
	char ch;

	sc = tc = nc = 0;
	while((ch = getchar()) != EOF) {
		if (ch == ' ') {
			++sc;
		}
		if (ch == '\t') {
			++tc;
		}
		if (ch == '\n') {
			++nc;
		}
	}

	printf("Space Count: %d\n Tab Count: %d\n End Of Line Count: %d\n", sc, tc, nc);
}