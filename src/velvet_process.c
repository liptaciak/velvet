#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <unistd.h>

#include <velvet.h>

velvet_message_t velvet_process(velvet_app_t* app, int client_fd) {
    velvet_message_t message;
    message.req = (char*)malloc(2048 * sizeof(char));

    ssize_t bytes_read = read(client_fd, message.req, 2048);
    if (bytes_read == 0) {
        close(client_fd);

        return message;
    }
   
    int cur = 0;

    char* request = (char*)malloc(2048 * sizeof(char));
    strcpy(request, message.req);
 
    char* req = strtok(request, " ");
    
    while(cur <= 1) {
        cur += 1;
        
        if (cur == 2) {
            for (int i = 0; i < app->routes; i++) {
                if(!strcmp(req, app->router[i].endpoint)) {
                    char* header = (char*)malloc(2048 * sizeof(char));
                    sprintf(header, "HTTP/1.1 %d\nContent-Type: %s\nConnection: close\n\n", app->router[i].response->code, app->router[i].response->content_type);

                    write(client_fd, header, strlen(header));
                    write(client_fd, app->router[i].response->content, strlen(app->router[i].response->content));

                    free(header);
                    break;
                }
            }
        }

        req = strtok(NULL, " ");
    }
    
    free(request);

    close(client_fd);
    return message;
}
