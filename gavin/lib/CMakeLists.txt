set(gavin_lib read.c log.c ../chap-11/grace_server.c ../chap-12/ping_server.c ../chap-12/ping_client.c ../chap-12/message_object.h ../chap-15/address_used.c ../chap-16/stream_server.c ../chap-16/stream_client.c ../chap-17/reliable_server01.c tcp_server.c tcp_server.h tcp_client.c ../chap-17/reliable_client01.c ../chap-18/buffer_client.c ../chap-18/samplebuffer01.c ../chap-22/nonblocking_client.c ../chap-22/nonblocking_server.c ../chap-22/aa.c ../reverse-linked-list/reverse.c ../chap-23/epoll01.c acceptor.h acceptor.c event_loop.h event_loop.c tcp_connection.h event_dispatcher.h channel.h buffer.h buffer.c tcp_connection.c channel.c utils.h utils.c log.h thread_pool.h thread_pool.c event_loop_thread.h event_loop_thread.c channel_map.h channel_map.c)


if (EPOLL_EXISTS)
    set(gavin_lib
            log.c
            read.c
            tcp_server.c
            tcp_client.c
            event_loop.c
            channel.c
            acceptor.c
            channel_map.c
            poll_dispatcher.c
            thread_pool.c
            event_loop_thread.c
            utils.c
            epoll_dispatcher.c
            buffer.c
            tcp_connection.c
            tcp_connection.c
            http_request.c
            http_response.c
            http_server.c)
else ()
    set(gavin_lib
            log.c
            read.c
            tcp_server.c
            tcp_client.c
            event_loop.c
            channel.c
            acceptor.c
            channel_map.c
            poll_dispatcher.c
            thread_pool.c
            event_loop_thread.c
            utils.c
            buffer.c
            tcp_connection.c
            http_request.c
            http_response.c
            http_server.c)
endif ()


add_library(gavin ${gavin_lib})
target_link_libraries(gavin pthread)

install(TARGETS gavin DESTINATION lib)