#include "lib/common.h"

#define  THREAD_NUMBER      4
#define  BLOCK_QUEUE_SIZE   100

extern void loop_echo(int);

typedef struct {
    pthread_t thread_tid;
    long thread_count;
} Thread;


Thread *thread_array;

typedef struct {
    int number;
    int *fd;
    int front;
    int rear;
    int count;
    pthread_mutex_t mutex;
    pthread_cond_t not_empty;
    // 队列未满条件
    pthread_cond_t not_full;
} block_queue;

void block_queue_init(block_queue *blockQueue, int number) {
    blockQueue->number = number;
    blockQueue->fd = calloc(number, sizeof(int));
    blockQueue->count=blockQueue->front = blockQueue->rear = 0;
    pthread_mutex_init(&blockQueue->mutex, NULL);
    pthread_cond_init(&blockQueue->not_empty, NULL);
    pthread_cond_init(&blockQueue->not_full, NULL);
}

void block_queue_push(block_queue *blockQueue, int fd) {
    pthread_mutex_lock(&blockQueue->mutex);
    while (blockQueue->count == blockQueue->number){   //队列满
        pthread_cond_wait(&blockQueue->not_full, &blockQueue->mutex);
    }
    blockQueue->fd[blockQueue->rear] = fd;
    if (++blockQueue->rear == blockQueue->number) {
        blockQueue->rear = 0;
    }
    blockQueue->count++;
    printf("push fd %d", fd);
    pthread_cond_signal(&blockQueue->not_empty);
    pthread_mutex_unlock(&blockQueue->mutex);
}

int block_queue_pop(block_queue *blockQueue) {
    pthread_mutex_lock(&blockQueue->mutex);
    while (blockQueue->front == blockQueue->rear)
        pthread_cond_wait(&blockQueue->not_empty, &blockQueue->mutex);
    int fd = blockQueue->fd[blockQueue->front];
    if (++blockQueue->front == blockQueue->number) {
        blockQueue->front = 0;
    }
    blockQueue->count--;
    printf("pop fd %d", fd);
    pthread_cond_signal(&blockQueue->not_full);
    pthread_mutex_unlock(&blockQueue->mutex);
    return fd;
}

void *thread_run(void *arg) {
    pthread_t tid = pthread_self();
    pthread_detach(tid);

    block_queue *blockQueue = (block_queue *) arg;
    while (1) {
        int fd = block_queue_pop(blockQueue);
        printf("get fd in thread, fd==%d, tid == %lu", fd, tid);
        loop_echo(fd);
    }
}

int main(int c, char **v) {
    int listener_fd = tcp_server_listen(SERV_PORT);

    block_queue blockQueue;
    block_queue_init(&blockQueue, BLOCK_QUEUE_SIZE);

    thread_array = calloc(THREAD_NUMBER, sizeof(Thread));
    int i;
    for (i = 0; i < THREAD_NUMBER; i++) {
        pthread_create(&(thread_array[i].thread_tid), NULL, thread_run, (void *) &blockQueue);
    }

    while (1) {
        struct sockaddr_storage ss;
        socklen_t slen = sizeof(ss);
        int fd = accept(listener_fd, (struct sockaddr *) &ss, &slen);
        if (fd < 0) {
            error(1, errno, "accept failed");
        } else {
            block_queue_push(&blockQueue, fd);
        }
    }

    return 0;
}





