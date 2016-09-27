#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE		64

int main(int argc, char ** argv)
{
	int fd;
	ssize_t read_bites;
	char buffer[BUFFER_SIZE + 1];

	if (argc < 2)
	{
		fprintf (stderr, "Too few arguments\n");
		exit (1);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		fprintf (stderr, "Cannot open file\n");
		exit (1);
	}

	while ((read_bites = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[read_bites] = 0;
		fputs(buffer, stdout);
	}

	close(fd);
	exit(0);
}