add_executable(streamserver stream_server.c)
target_link_libraries(streamserver gavin)

add_executable(streamclient stream_client.c)
target_link_libraries(streamclient gavin)