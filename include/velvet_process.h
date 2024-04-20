#ifndef __VELVET_PROCESS__
#define __VELVET_PROCESS__

typedef struct __velvet_message_t {
    char* res;
    char* req;
} velvet_message_t;

velvet_message_t* velvet_process(int client_fd);

#endif /* __VELVET_PROCESS__ */
