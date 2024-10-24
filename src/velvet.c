#include <stdio.h>
#include <stdlib.h>

#include <sys/socket.h>
#include <netinet/in.h>

#include <velvet.h>

velvet_app_t* velvet_create_app(void) {
    // Create TCP/IP socket and store return value
    int socket_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (socket_fd == -1) {
        perror("app");
        exit(1);
    }
    
    // Allocate memory for 'velvet_app_t' and store socket file descriptor
    velvet_app_t* app = (velvet_app_t*)calloc(1, sizeof(velvet_app_t));
    app->socket = socket_fd;
    
    return app;
}
