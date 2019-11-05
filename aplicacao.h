#ifndef APLICACAO_H
#define APLICACAO_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "transporte.h"

const unsigned short SERVER_PORT = 6969;

typedef struct{
    void *buffer;
    size_t buffer_size;
} File;

bool load_file(const char *path, File *file);
bool send_file(const char *server_ip, const File *file);
void close_file(File *file);

#endif
