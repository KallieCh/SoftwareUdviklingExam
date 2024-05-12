cmake_minimum_required(VERSION 3.5)

project(Final LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5Sql REQUIRED)

add_executable(Final main.cpp
    hero.h hero.cpp
    gamestate.h gamestate.cpp
    client.h client.cpp
    enemy.h enemy.cpp)
target_link_libraries(Final Qt5::Core Qt5::Sql)

include(GNUInstallDirs)
install(TARGETS Final
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
