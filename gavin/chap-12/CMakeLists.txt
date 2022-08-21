add_executable(pingserver ping_server.c)
target_link_libraries(pingserver gavin)

add_executable(pingclient ping_client.c)
target_link_libraries(pingclient gavin)