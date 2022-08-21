//
// Created by chenlh on 2022/9/1.
//

#ifndef GAVIN_CHANNEL_H
#define GAVIN_CHANNEL_H

#include "common.h"
#include "event_loop.h"
#include "buffer.h"

#define EVENT_TIMEOUT    0x01
#define EVENT_READ        0x02
#define EVENT_WRITE    0x04
#define EVENT_SIGNAL    0x08

typedef int (*event_read_callback)(void *data);

typedef int (*event_write_callback)(void *data);

struct channel {
    int fd;
    int events;

    event_read_callback eventReadCallback;
    event_write_callback eventWriteCallback;
    void *data;
};


struct channel *
        channel_new(int fd, int events, event_read_callback eventReadCallback, event_write_callback eventWriteCallback,
                    void *data);

int channel_write_event_is_enabled(struct channel *channel);

int channel_write_event_enable(struct channel *channel);

int channel_write_event_disable(struct channel *channel);

#endif //GAVIN_CHANNEL_H
