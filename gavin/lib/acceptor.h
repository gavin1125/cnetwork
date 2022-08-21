//
// Created by chenlh on 2022/9/1.
//

#ifndef GAVIN_ACCEPTOR_H
#define GAVIN_ACCEPTOR_H

#include "common.h"

struct acceptor{
    int listen_port;
    int listen_fd;
} ;

struct acceptor *acceptor_init(int port);

#endif //GAVIN_ACCEPTOR_H
