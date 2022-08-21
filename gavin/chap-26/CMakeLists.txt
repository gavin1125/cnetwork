add_executable(thead-helloworld thead-helloworld.c)
target_link_libraries(thead-helloworld gavin)

add_executable(thread01 thread01.c echo.c)
target_link_libraries(thread01 gavin)

add_executable(thread02 thread02.c echo.c)
target_link_libraries(thread02 gavin)
