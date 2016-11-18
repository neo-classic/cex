#include <stdio.h>

int main(void)
{
	char ch;
	int lengts[10], i;

	for(i = 0; i < 10; i++) {
		lengts[i] = 0;
	}
	i = 0;

	while ((ch = getchar()) != EOF) {
		if (ch == ' ' || ch == '\n' || ch == '\t') {
			if (i == 0) continue;
			if (i > 9) {
				lengts[0] = lengts[0] + 1;
			} else {
				lengts[i] = lengts[i] + 1;
			}
			i = 0;
		} else {
			++i;
		}
	}

	for (i = 0; i < 10; i++) {
		printf("Length %d: ", i);
		for (int j = 0; j < lengts[i]; j++) {
			printf("-");
		}
		printf("> %d\n", lengts[i]);
	}
}
