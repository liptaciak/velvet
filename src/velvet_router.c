#include <stdlib.h>

#include <velvet.h>

void velvet_add_route(velvet_app_t* app, velvet_method_t method, char* endpoint, velvet_response_t (*response)(velvet_request_t)) {
    velvet_route_t route = { method, endpoint, response };
    
    // Resize the router buffer and store new route
    app->router = realloc(app->router, (app->routes + 1) * sizeof(velvet_route_t));
    app->router[app->routes] = route;
    
    // Increase the size of 'app->routes' to track size of buffer
    app->routes++;
}
