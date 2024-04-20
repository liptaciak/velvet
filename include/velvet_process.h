#ifndef __VELVET_PROCESS__
#define __VELVET_PROCESS__

#include <stdint.h>

typedef struct __velvet_response_t {
    uint16_t code;
    char* content_type;
    char* content;
} velvet_response_t;

typedef char* velvet_request_t;

typedef struct __velvet_message_t {
    velvet_response_t* res;
    velvet_request_t* req;
} velvet_message_t;

velvet_message_t* velvet_process(int client_fd);

#endif /* __VELVET_PROCESS__ */
