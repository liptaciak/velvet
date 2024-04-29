#ifndef __VELVET__
#define __VELVET__

#include <stdint.h>

typedef enum __velvet_method_t {
    GET
} velvet_method_t;

typedef struct __velvet_response_t {
    uint16_t code;
    char* content_type;
    char* content;
} velvet_response_t;

typedef char* velvet_request_t;

typedef struct __velvet_message_t {
    velvet_response_t res;
    velvet_request_t req;
} velvet_message_t;

typedef struct __velvet_route_t {
    velvet_method_t method;
    char* endpoint;
    velvet_response_t* response;
} velvet_route_t;

typedef struct __velvet_app_t {
    int socket;
    uint16_t routes;
    velvet_route_t *router;
} velvet_app_t;

velvet_app_t* velvet_create_app(void);

void velvet_listen(velvet_app_t* app, uint16_t port);

velvet_message_t velvet_process(velvet_app_t* app, int client_fd);

void velvet_add_route(velvet_app_t* app, velvet_method_t method, char* endpoint, velvet_response_t* response);

#endif /* __VELVET__ */
