#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <vector>
#include <string>
#include <fcntl.h>
#include <unistd.h>

const char *fifoFile = "./fifo-test";

int main () {
	FILE *fp;
	unlink (fifoFile);
	int hnd;
	if (mkfifo (fifoFile, 0666) < 0) {
		printf ("Cant create fifo\n");
		return 1;
	}
    if ((hnd = open (fifoFile, O_RDONLY | O_NONBLOCK)) < 0) {
        printf ("Cant open fifo file\n");
		return 1;
	}
    char n, buff [1024];
	while (1) {
        if ((n = read (hnd, buff, 1024)) > 0) {
			printf ("string content: %s", buff);
		}
		printf ("string length: %d\n", n);
		sleep (1);
	}
	return 0;
}