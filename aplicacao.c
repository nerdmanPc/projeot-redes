#include "aplicacao.h"

bool load_file(const char *path, File *file)
{
    file->buffer = NULL;
    file->buffer_size = 0;
    FILE *file_handle = fopen(path, "rb");
    if (file_handle == NULL){
        return false;
    }
    getdelim((char**) &(file->buffer), &(file->buffer_size), EOF, file_handle);
    fclose(file_handle);
    return true;
}

bool send_file(const char *server_ip, const File *file)
{
    Socket server;
    socket_init(&server);
    bool connect_success = socket_connect(&server, server_ip, SERVER_PORT);
    if (!connect_success){
        return false;
    }
    bool send_success = socket_send(&server, file->buffer, file->buffer_size);
    if (!send_success){
        return false;
    }
    socket_close(&server);
    return true;
}

void close_file(File *file)
{
    free(file->buffer);
    file->buffer = NULL;
    file->buffer_size = 0;
}