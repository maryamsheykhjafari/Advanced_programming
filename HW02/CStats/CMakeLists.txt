cmake_minimum_required(VERSION 3.5)

project(Cstats LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Cstats main.cpp
    Cstats.h)

include(GNUInstallDirs)
install(TARGETS Cstats
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
