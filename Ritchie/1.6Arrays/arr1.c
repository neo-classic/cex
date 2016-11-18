#include <stdio.h>

int main(void)
{
	char ch;
	int i, nwhite, nother;
	int ndigit[10];

	nwhite = nother = 0;
	for (i = 0; i < 10; i++) {
		ndigit[i] = 0;
	}

	while ((ch = getchar()) != EOF) {
		if (ch >= '0' && ch <= '9') {
			++ndigit[ch-'0'];
			printf("%c : %d\n", ch, ch);
		} else if (ch == ' ' || ch == '\n' || ch == '\t') {
			++nwhite;
		} else {
			++nother;
		}
	}

	printf("digits =");
	for (i = 0; i < 10; i++) {
		printf(" %d", ndigit[i]);
	}
	printf(", white space = %d, other = %d\n", nwhite, nother);
}
