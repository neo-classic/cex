#include <stdio.h>
#include <stdlib.h>
#include "unistd.h"
#include <string.h>

extern char ** environ;

int main(int argc, char ** argv)
{
	int i;
	if (argc != 2) {
		fprintf(stderr, "environ: Too few(or less) arguments\n");
		fprintf(stderr, "Usage: environ <variable>\n");
		exit(1);
	}

	for(i=0; environ[i] != NULL; i++) {
		if (!strncmp(environ[i], argv[1], strlen(argv[1]))) {
			printf("'%s' found\n", environ[i]);
			exit(0);
		}
	}
	printf("'%s' not found\n", argv[1]);
	exit(0);
}