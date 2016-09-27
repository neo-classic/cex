#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main (int argc, char ** argv)
{
	int fd;
	mode_t mode = S_IRUSR | S_IWUSR;
	int flags = O_WRONLY | O_CREAT | O_EXCL;

	if (argc < 2) {
		fprintf (stderr, "openclose: Too few arguments\n");
		fprintf (stderr, "Usage: openclose <filename>\n");
		exit (1);
	}

	fd = open(argv[1], flags, mode);
	if (fd < 0) {
		fprintf (stderr, "openclose: Cannot open file '%s'\n", argv[1]);
		exit (1);
	}

	if (close(fd) != 0) {
		fprintf (stderr, "Cannot close file (descriptor=%d)\n", fd);
		exit (1);
	}

	exit(0);
}