cmake_minimum_required(VERSION 3.5)

project(p02_circle LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(p02_circle main.cpp
    circle.h circle.cpp)

include(GNUInstallDirs)
install(TARGETS p02_circle
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
