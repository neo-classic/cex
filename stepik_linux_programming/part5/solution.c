#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <unistd.h>

#define BUFFER 5120

struct sockaddr_in local;

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("USAGE: ./udp_log [PORT]");
        exit(1);
    }

    char str[BUFFER];
    int port = atoi(argv[1]);
    int sd;

    sd = socket(AF_INET, SOCK_DGRAM, 0);
    inet_aton("127.0.0.1", &local.sin_addr);
    local.sin_port = htons(port);
    local.sin_family = AF_INET;

    int result = bind(sd, (struct sockaddr*) &local, sizeof(local));

    while (1) {
        memset(&str[0], 0, sizeof(str));
        read(sd, str, BUFFER);
        if (strncmp(str, "OFF\n", 4) == 0) {
            exit(0);
        }
        printf("%s\n", str);
    }


    return 0;
}