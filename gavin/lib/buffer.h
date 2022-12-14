//
// Created by chenlh on 2022/9/1.
//

#ifndef GAVIN_BUFFER_H
#define GAVIN_BUFFER_H
#define INIT_BUFFER_SIZE 65536

struct buffer {
    char *data;
    int readIndex;
    int writeIndex;
    int total_size;
};

struct buffer *buffer_new();

void buffer_free(struct buffer *buffer);

int buffer_writeable_size(struct buffer *buffer);

int buffer_readable_size(struct buffer *buffer);

int buffer_front_spare_size(struct buffer *buffer);

int buffer_append(struct buffer *buffer, void *data, int size);

int buffer_append_char(struct buffer *buffer, char data);

int buffer_append_string(struct buffer *buffer, char *data);

int buffer_socket_read(struct buffer *buffer, int fd);

char buffer_read_char(struct buffer *buffer);

char *buffer_find_CRLF(struct buffer *buffer);

#endif //GAVIN_BUFFER_H
