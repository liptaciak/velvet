#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <velvet.h>

velvet_message_t velvet_process(velvet_app_t* app, int client_fd) {
    velvet_message_t message;
    read(client_fd, message.req, 2048);

    int cur = 0;
    char *req = strtok(message.req, " ");
    
    while(cur <= 1) {
        cur += 1;

        if(req == app->router[0].endpoint) {
            printf("%s", req);
        }
        printf("%s", req);

        req = strtok(NULL, " ");
    }

    return message;
}
