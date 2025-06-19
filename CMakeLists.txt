cmake_minimum_required(VERSION 3.16)

project(stream-bridge LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Collect headers and sources (you can also list them manually if preferred)
set(STREAM_BRIDGE_HEADERS
    iosfwd-bridge.h
    ios-bridge.h
    istream-bridge.h
    ostream-bridge.h
    iostream-bridge.h
    iomanip-bridge.h
    sstream-bridge.h
    fstream-bridge.h
    ios-base-impl.h
    istream-impl.h
    ostream-impl.h
    iostream-template.h
)

set(STREAM_BRIDGE_SOURCES
    ios-bridge.cpp
    istream-bridge.cpp
    ostream-bridge.cpp
    iostream-bridge.cpp
    iomanip-bridge.cpp
    sstream-bridge.cpp
    fstream-bridge.cpp
)

add_library(stream-bridge STATIC
    ${STREAM_BRIDGE_HEADERS}
    ${STREAM_BRIDGE_SOURCES}

    
)

target_include_directories(stream-bridge PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Optional install rule
include(GNUInstallDirs)
install(TARGETS stream-bridge
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
