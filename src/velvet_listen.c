#include <time.h>

#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#include <sys/socket.h>
#include <netinet/in.h>

#include <velvet.h>

void velvet_listen(velvet_app_t* app, uint16_t port) {
    struct sockaddr_in addr = { AF_INET, htons(port), { INADDR_ANY }, { 0 } };
    
    // Bind the server socket to listen on 'port'
    int res = bind(app->socket, (struct sockaddr*)&addr, sizeof(addr));
    if (res == -1) {
        perror("bind");
        exit(1);
    }
    
    // The server will handle max of 128 connections at once
    listen(app->socket, 128); 

    socklen_t socklen = sizeof(addr);

    velvet_message_t message;
    int client_fd;
    
    //TODO: Free used port on exit

   while(1) {
        // Accept and process user request
        // If the operation was successful, continue the loop
        client_fd = accept(app->socket, (struct sockaddr*)&addr, &socklen);

        clock_t start_clock = clock();
        message = velvet_process(app, client_fd); //TODO: Add multithreading

        char *line = strtok(message.req, "\n");
        if (line != NULL) {
            printf("%s\nTook %.3f ms\n\n", line, ((double)start_clock) / CLOCKS_PER_SEC * 1000);
        }
        
        // Free the buffer allocated while processing request
        free(message.req);
    }
}
