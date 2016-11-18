#include <stdio.h>

int main(void)
{
	char ch;

	while ((ch = getchar()) != EOF)
	{
		if (ch != ' ' && ch != '\n' && ch != '\t') {
			putchar(ch);
		} else {
			putchar('\n');
		}
	}
}