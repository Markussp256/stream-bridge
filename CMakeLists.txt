cmake_minimum_required(VERSION 3.16)

project(StreamBridge LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(StreamBridge main.cpp
    ostream-bridge.h
    ostream-bridge.cpp
    
    iostream-bridge.h
    iostream-bridge.cpp

    sstream-bridge.h
    sstream-bridge.cpp
    
    fstream-bridge.h
    fstream-bridge.cpp
    
    ostream-impl.h
    iosfwd-bridge.h
)
    

include(GNUInstallDirs)
install(TARGETS StreamBridge
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
