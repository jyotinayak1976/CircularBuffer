#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#include "circular_buffer.h"

CircularBuffer cb;

void *producer(void *arg)
{
    for (int i = 1; i <= 50; i++)
    {
        printf("Producing %d\n", i);

        cb_push(&cb, i);

        usleep(100000);
    }

    return NULL;
}

void *consumer(void *arg)
{
    while (1)
    {
        int value = cb_pop(&cb);

        printf("Consumed %d\n", value);

        usleep(200000);
    }

    return NULL;
}

int main()
{
    pthread_t p1, c1;

    cb_init(&cb);

    pthread_create(&p1, NULL, producer, NULL);
    pthread_create(&c1, NULL, consumer, NULL);

    pthread_join(p1, NULL);
    pthread_join(c1, NULL);

    return 0;
}
