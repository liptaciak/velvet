#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <velvet_process.h>

velvet_message_t* velvet_process(int client_fd) {
    velvet_message_t* message = (velvet_message_t*)calloc(1, sizeof(velvet_message_t));
    read(client_fd, message->req, 2048);

    return message;
}
