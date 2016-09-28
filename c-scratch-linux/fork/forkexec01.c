#include <unistd.h>
#include <stdio.h>

extern char ** environ;

int main(void)
{
	char * echo_argv[] = {"ls", "/", NULL};
	if (!fork()) {
		execve("/bin/ls", echo_argv, environ);
		fprintf (stderr, "an error occured\n");
		return 1;
	}

	printf ("parent\n");
	return 0;
}