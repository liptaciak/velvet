#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <velvet_socket.h>

int velvet_create_socket() {
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        perror("socket");
        exit(1);
    }

    return socket_fd;
}