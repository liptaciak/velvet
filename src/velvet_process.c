#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <unistd.h>

#include <velvet.h>

velvet_message_t velvet_process(velvet_app_t* app, int client_fd) {
    velvet_message_t message;
    message.req = (char*)malloc(2048 * sizeof(char)); // Allocate memory for user request

    ssize_t bytes_read = read(client_fd, message.req, 2048); //TODO: Resize buffer if not the full request was read
    if (bytes_read <= 0) {
        close(client_fd); // Close connection if request was not read
        
        return message;
    }
   
    int cur = 0;

    char* request = (char*)malloc(2048 * sizeof(char));
    strcpy(request, message.req);
    
    // TODO: Store parsed request fields
    // velvet_request_t request...

    char* req = strtok(request, " ");

    while(cur <= 1) {
        cur += 1;
        
        if (cur == 2) { // If 'cur == 2' then 'req' is the full request path
            for (int i = 0; i < app->routes; i++) {
                if(!strcmp(req, app->router[i].endpoint)) {
                    velvet_response_t response = app->router[i].response(message.req); // Pass user request as a parameter to route function

                    char* header = (char*)malloc(2048 * sizeof(char));
                    sprintf(header, "HTTP/1.1 %d\nContent-Type: %s\nConnection: close\n\n", response.code, response.content_type);
                    
                    // Write header and response from route function to socket
                    // TODO: Read header content from server response
                    write(client_fd, header, strlen(header));
                    write(client_fd, response.content, strlen(response.content));

                    free(header);
                    break;
                }
            }
        }

        // TODO: Store response that was sent to client in 'message.res'
    
        req = strtok(NULL, " ");
    }
    
    free(request);
    
    // Close connection and return message sent to socket
    close(client_fd);
    return message;
}
