#include <velvet.h>

#include <stdio.h>
#include <stdint.h>
 
const uint16_t PORT = 7777;

int main(int argc, char **argv) {
    velvet_app_t* app = velvet_create_app();

    velvet_method_t method = GET;
    velvet_response_t response = {
        .code = 200,
        .content_type = "text/json",
        .content = "{ code: 200, message: '/' }",
    };

    velvet_add_route(app, method, "/", &response);

    printf("Server listening on port %d\n\n", PORT);
    velvet_listen(app, PORT);
}
