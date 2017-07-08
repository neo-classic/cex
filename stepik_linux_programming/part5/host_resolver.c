// Host resolver
//
// Разработайте утилиту командной строки, принимающую на вход имя хоста и печатающую в стандартный поток вывода список IP-адресов,
//  ассоциированных с данным именем.

#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char **argv)
{
    if (argc != 2) {
        return -1;
    }

    struct hostent *h;
    h = gethostbyname(argv[1]);

    if (NULL == h) {
        printf("Error\n");
        return -1;
    }

    int i = 0;
    while (h->h_addr_list[i] != NULL) {
        struct in_addr *a = (struct in_addr*) h->h_addr_list[i];
        printf("%s\n", inet_ntoa(*a));
        i++;
    }

    return 0;
}