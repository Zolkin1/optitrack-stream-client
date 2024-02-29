add_executable(interface interface_app.cpp)
add_executable(client client_app.cpp)

target_link_libraries(interface PUBLIC stream_client)
target_link_libraries(client PUBLIC stream_client)