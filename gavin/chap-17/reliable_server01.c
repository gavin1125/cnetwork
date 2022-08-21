#include "lib/common.h"

int main(int argc, char **argv) {
    int connfd;
    char buf[1024];

    connfd = tcp_server(SERV_PORT);

    for (;;) {
        int n = read(connfd, buf, 1024);
        if (n < 0) {
            error(1, errno, "error read");
        } else if (n == 0) {
            error(1, 0, "client closed");
        }
        sleep(5);

        int write_nc = send(connfd, buf, n, 0);
        printf("send bytes: %d", write_nc);
        if (write_nc < 0) {
            error(1, errno, "error write");
        }
    }
}