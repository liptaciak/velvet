#ifndef __VELVET__
#define __VELVET__

typedef struct __velvet_app_t {
    int socket;
} velvet_app_t;

velvet_app_t* velvet_create_app(void);

#endif /* __VELVET__ */
