#include <stdio.h>

#define IN  1
#define OUT 0

int main(void)
{
	char ch;
	int nl, nw, nc, state;

	state = OUT;
	nl = nw = nc = 0;

	while ((ch = getchar()) != EOF) {
		++nc;
		if (ch == '\n') {
			++nl;
		}
		if (ch == ' ' || ch == '\t' || ch == '\n') {
			state = OUT;
		} else if (state == OUT) {
			state = IN;
			++nw;
		}
	}

	printf("Lines: %d\nWords: %d\nChars: %d\n", nl, nw, nc);
}