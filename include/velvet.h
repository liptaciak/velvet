#ifndef __VELVET__
#define __VELVET__

#include <stdint.h>
#include <velvet_router.h>

typedef struct __velvet_app_t {
    int socket;
    uint16_t routes;
    velvet_route_t router[];
} velvet_app_t;

typedef enum __velvet_method_t {
    GET
    //other methods will be implemented soon
} velvet_method_t;

velvet_app_t* velvet_create_app(void);

#endif /* __VELVET__ */
