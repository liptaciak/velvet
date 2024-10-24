
# Velvet - HTTP Library written in C

[![GPLv3 License](https://img.shields.io/badge/License-GPL%20v3-yellow.svg)](https://opensource.org/licenses/) 
![GitHub top language](https://img.shields.io/github/languages/top/liptaciak/velvet?logoColor=white&label=C)
![GitHub Repo stars](https://img.shields.io/github/stars/liptaciak/velvet?style=flat&label=Stars)

Velvet is a simple HTTP library / Web server for C/C++.

## Usage/Examples

Example code below creates a route at "/" and listens at port 8080:

```C
#include <velvet.h>

velvet_response_t route(velvet_request_t req) {
    velvet_response_t response = {
        .code = 200,
        .content_type = "text/plain",
        .content = "Hello World!"
    };

    return response;
}

int main(int argc, char **argv) {
    velvet_app_t* app = velvet_create_app();
    
    velvet_method_t method = GET;
    velvet_add_route(app, method, "/", route);

    velvet_listen(app, 8080);
}
```
