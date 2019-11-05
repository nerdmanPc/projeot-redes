#ifndef TRANSPORTE_H
#define TRANSPORTE_H

#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

typedef struct {
    //TODO
} Socket;

void socket_init(Socket *socket);
bool socket_connect(Socket *socket, const char *server_ip, unsigned short server_port);
bool socket_send(Socket *socket, void *buffer, size_t buffer_size);
bool socket_recieve(Socket *socket, void **buffer, size_t *buffer_size);
void socket_close(Socket *socket);

#endif