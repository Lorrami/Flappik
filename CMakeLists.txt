cmake_minimum_required(VERSION 3.10)
project(Shooter)

set(CMAKE_CXX_STANDARD 17)

set(SHOOTER_SOURCES
        "Game/main.cpp"
        "Sources/GameObject.cpp")

add_subdirectory(SFML)

add_executable(Shooter ${SHOOTER_SOURCES})
target_link_libraries(Shooter sfml-graphics sfml-system sfml-window)
