#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <pthread.h>

#define BUFFER_SIZE 8

typedef struct {
    int buffer[BUFFER_SIZE];
    int head;
    int tail;
    int count;

    pthread_mutex_t mutex;
    pthread_cond_t not_full;
    pthread_cond_t not_empty;

} CircularBuffer;

void cb_init(CircularBuffer *cb);

void cb_push(CircularBuffer *cb, int value);

int cb_pop(CircularBuffer *cb);

#endif
