cmake_minimum_required(VERSION 3.5)

project(Employee LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Employee main.cpp
    employee.h)

include(GNUInstallDirs)
install(TARGETS Employee
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
