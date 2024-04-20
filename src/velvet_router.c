#include <stdlib.h>

#include <velvet.h>
#include <velvet_process.h>

#include <velvet_router.h>

void velvet_add_route(velvet_app_t app, velvet_method_t method, char* endpoint, velvet_response_t* response) {
    velvet_route_t route = { method, endpoint, response };

    app->router = realloc(app->router, (app->routes + 1) * sizeof(velvet_route_t));
    app->router[app->routes] = route;

    app->routes++;
}
