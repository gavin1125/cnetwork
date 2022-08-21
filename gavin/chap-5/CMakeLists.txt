add_executable(tcpserver tcp_server.c)
target_link_libraries(tcpserver gavin)

add_executable(tcpclient tcp_client.c)
target_link_libraries(tcpclient gavin)