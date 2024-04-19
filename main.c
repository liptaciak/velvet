#include <stdio.h>
#include <velvet_socket.h>

int main() {
    int socket = velvet_create_socket();
    printf("%d", socket);
}