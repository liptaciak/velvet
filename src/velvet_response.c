#include <stdlib.h>

#include <velvet.h>

void velvet_add_header(velvet_response_t* response, char* name, char* value) {
    velvet_header_t header = { name, value };
    
    // Resize the header buffer and store new header
    response->header = realloc(response->header, (response->headers + 1) * sizeof(velvet_header_t));
    response->header[response->headers] = header;
    
    // Increase the size of 'app->headers' to track size of buffer
    response->headers++;
}
