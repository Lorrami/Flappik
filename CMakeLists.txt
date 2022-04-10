cmake_minimum_required(VERSION 3.10)
project(FlappikPlus)

set(CMAKE_CXX_STANDARD 14)

set(SOURCES
        "sources/main.cpp"
        "sources/Application.cpp"
        "sources/GameObject.cpp"
        "sources/Level.cpp"
        "sources/Bird.cpp"
        "sources/Block.cpp"
        "sources/Bullet.cpp")

add_subdirectory(SFML)

add_executable(FlappikPlus ${SOURCES})
target_link_libraries(FlappikPlus sfml-graphics sfml-system sfml-window)
