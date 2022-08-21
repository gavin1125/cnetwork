#ifndef COMMON_H
#define COMMON_H

#define __USE_GNU
#define _GNU_SOURCE

#include "config.h"
#include "log.h"
#include "channel_map.h"

#include <poll.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <strings.h>
#include <string.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <signal.h>
#include <fcntl.h>
#include <pthread.h>
#include <sys/uio.h>

#ifdef EPOLL_ENABLE

#include    <sys/epoll.h>

#endif

size_t readn(int fd, void *buffer, size_t size);

size_t read_message(int fd, char *buffer, size_t length);

size_t readline(int fd, char *buffer, size_t length);

int tcp_server(int port);

int tcp_client(char *address, int port);

int tcp_nonblocking_server_listen(int port);

int tcp_server_listen(int port);

void make_nonblocking(int fd);

void error(int status, int err, char *fmt, ...);


#define SERV_PORT 43211
#define LISTENQ 1024
#define MAXLINE 4096

#endif //COMMON_H