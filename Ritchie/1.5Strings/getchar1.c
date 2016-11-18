#include <stdio.h>

int main(void)
{
	char c;

	while((c = getchar()) != EOF) {
		printf(" = ");
		putchar(c);
	}
}