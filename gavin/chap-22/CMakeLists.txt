add_executable(nonblockingserver nonblocking_server.c)
target_link_libraries(nonblockingserver gavin)

add_executable(nonblockingclient nonblocking_client.c)
target_link_libraries(nonblockingclient gavin)

add_executable(aa aa.c)
target_link_libraries(aa gavin)