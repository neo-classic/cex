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
	ssize_t read_bytes;
	ssize_t written_bytes;
	char buffer[BUFFER_SIZE];

	if (argc < 2)
	{
		fprintf (stderr, "Too few arguments\n");
		exit (1);
	}

	fd = open (argv[1], O_RDONLY);
	if (fd < 0)
	{
		fprintf (stderr, "Cannot open file\n");
		exit (1);
	}

	while ((read_bytes = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		written_bytes = write(1, buffer, read_bytes);
		if (written_bytes != read_bytes) {
			fprintf (stderr, "Cannot write\n");
			exit (1);
		}
	}

	if (read_bytes < 0)
	{
		fprintf (stderr, "myread: Cannot read file\n");
		exit (1);
	}
	close (fd);
	exit (0);
}