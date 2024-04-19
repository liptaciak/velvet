#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <velvet.h>
#include <velvet_listen.h>

void velvet_listen(velvet_app_t app, uint16_t port) {
    struct sockaddr_in addr = { AF_INET, htons(port), { INADDR_ANY }, { 0 } };

    int res = bind(app.socket, (struct sockaddr*) &addr, sizeof(addr));
    if (res == -1) {
        perror("bind");
        exit(1);
    }

    listen(app.socket, 128);

    socklen_t socklen = sizeof(addr);
    accept(app.socket, (struct sockaddr*) &addr, &socklen);
}
