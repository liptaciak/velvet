#ifndef __VELVET_ROUTER__
#define __VELVET_ROUTER__

#include <velvet.h>
#include <velvet_process.h>

typedef struct __velvet_route_t {
    velvet_method_t method;
    char* endpoint;
    velvet_response_t* response;
} velvet_route_t;

void velvet_add_route(velvet_app_t* app, velvet_method_t method, char* endpoint, velvet_response_t* response);

#endif /* __VELVET_ROUTER__ */
