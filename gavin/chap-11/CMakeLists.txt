add_executable(graceserver grace_server.c)
target_link_libraries(graceserver gavin)

add_executable(graceclient grace_client.c)
target_link_libraries(graceclient gavin)