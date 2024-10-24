#include <velvet.h>

#include <stdio.h>
#include <stdint.h>
 
const uint16_t PORT = 7777;

velvet_response_t index_route(velvet_request_t request) {
    velvet_response_t response = {
        .code = 200,
        .content_type = "text/json",
        .content = "{ code: 200, message: '/' }",
    };

    return response;
}

int main(int argc, char **argv) {
    velvet_app_t* app = velvet_create_app();
    
    velvet_method_t method = GET;
    velvet_add_route(app, method, "/", index_route);

    printf("Server listening on port %d\n\n", PORT);
    velvet_listen(app, PORT);
}
