
set(STREAM_CLIENT_HEADERS
        "${optitrack-stream-client_SOURCE_DIR}/stream_client/include/shared_data.h"
        "${optitrack-stream-client_SOURCE_DIR}/stream_client/include/client.h"
        "${optitrack-stream-client_SOURCE_DIR}/stream_client/include/client_interface.h"
        "${optitrack-stream-client_SOURCE_DIR}/stream_client/include/NatNetCAPI.h"
        "${optitrack-stream-client_SOURCE_DIR}/stream_client/include/NatNetClient.h"
        "${optitrack-stream-client_SOURCE_DIR}/stream_client/include/NatNetRepeater.h"
        "${optitrack-stream-client_SOURCE_DIR}/stream_client/include/NatNetRequests.h"
        "${optitrack-stream-client_SOURCE_DIR}/stream_client/include/NatNetTypes.h")

add_library(stream_client
        client.cpp
        client_interface.cpp
        ${STREAM_CLIENT_HEADERS})

target_include_directories(stream_client PUBLIC
        $<BUILD_INTERFACE:${optitrack-stream-client_SOURCE_DIR}/stream_client/include>
        $<INSTALL_INTERFACE:include/optitrack-stream-client>)

#target_include_directories(stream_client PUBLIC include)

# boost
find_package(Boost REQUIRED)
message(STATUS "Boost FOUND")
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})

target_link_libraries(stream_client PRIVATE ${Boost_LIBRARIES})

# NatNet
#link_directories(${CMAKE_SOURCE_DIR}/stream_client/lib)
target_link_libraries(stream_client PUBLIC /home/zolkin/AmberLab/tools/optitrack-stream-client/stream_client/lib/libNatNet.so)

# Eigen
find_package(Eigen3 REQUIRED)
target_link_libraries(stream_client PUBLIC Eigen3::Eigen)

add_library(optitrack-stream-client::stream-client ALIAS stream_client)

install(TARGETS stream_client
        EXPORT ${PROJECT_NAME}
        LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
        ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}"
        RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
        PUBLIC_HEADER DESTINATION "${CMAKE_INSTALL_INCLUDE_DIR}/optitrack-stream-client")

install_basic_package_files(${PROJECT_NAME}
        NAMESPACE optitrack-stream-client::
        VERSION ${${PROJECT_NAME}_VERSION}
        COMPATIBILITY SameMajorVersion
        VARS_PREFIX ${PROJECT_NAME}
        NO_CHECK_REQUIRED_COMPONENTS_MACRO
        DEPENDENCIES "Eigen3 CONFIG")

install(FILES ${STREAM_CLIENT_HEADERS} DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/optitrack-stream-client")