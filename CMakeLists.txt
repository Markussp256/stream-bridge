cmake_minimum_required(VERSION 3.16)

project(stream-bridge LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define your include paths
set(PUBLIC_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(PRIVATE_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")


# Collect headers and sources (you can also list them manually if preferred)
set(STREAM_BRIDGE_PUBLIC_HEADERS
    ${PUBLIC_INCLUDE_DIR}/iosfwd-bridge.h
    ${PUBLIC_INCLUDE_DIR}/ios-bridge.h
    ${PUBLIC_INCLUDE_DIR}/istream-bridge.h
    ${PUBLIC_INCLUDE_DIR}/ostream-bridge.h
    ${PUBLIC_INCLUDE_DIR}/iostream-bridge.h
    ${PUBLIC_INCLUDE_DIR}/iomanip-bridge.h
    ${PUBLIC_INCLUDE_DIR}/sstream-bridge.h
    ${PUBLIC_INCLUDE_DIR}/fstream-bridge.h
    ${PUBLIC_INCLUDE_DIR}/string-fwd.h
)

set(STREAM_BRIDGE_PRIVATE_HEADERS
    ${PRIVATE_INCLUDE_DIR}/ios-base-impl.h
    ${PRIVATE_INCLUDE_DIR}/istream-impl.h
    ${PRIVATE_INCLUDE_DIR}/ostream-impl.h
    ${PRIVATE_INCLUDE_DIR}/iostream-template.h
    ${PRIVATE_INCLUDE_DIR}/bitmap-conversion.h
)

set(STREAM_BRIDGE_SOURCES
    ${PRIVATE_INCLUDE_DIR}/ios-bridge.cpp
    ${PRIVATE_INCLUDE_DIR}/istream-bridge.cpp
    ${PRIVATE_INCLUDE_DIR}/ostream-bridge.cpp
    ${PRIVATE_INCLUDE_DIR}/iostream-bridge.cpp
    ${PRIVATE_INCLUDE_DIR}/ios-base-impl.cpp
    ${PRIVATE_INCLUDE_DIR}/iomanip-bridge.cpp
    ${PRIVATE_INCLUDE_DIR}/sstream-bridge.cpp
    ${PRIVATE_INCLUDE_DIR}/fstream-bridge.cpp
)

add_library(stream-bridge STATIC
    ${STREAM_BRIDGE_PRIVATE_HEADERS}
    ${STREAM_BRIDGE_PUBLIC_HEADERS}
    ${STREAM_BRIDGE_SOURCES}
)

target_include_directories(stream-bridge PUBLIC
    PUBLIC  ${PUBLIC_INCLUDE_DIR}
    PRIVATE ${PRIVATE_INCLUDE_DIR}
)

# Optional install rule
include(GNUInstallDirs)
install(TARGETS stream-bridge
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Optionally install public headers
install(FILES ${STREAM_BRIDGE_PUBLIC_HEADERS}
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
