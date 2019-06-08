cmake_minimum_required(VERSION 3.13)
project(Snake)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -Wextra -Werror -Wpedantic -pedantic-errors)

include_directories(
        include
)

set(SOURCE_FILES
       src/Snake.cpp
        )

add_executable(Snake__debug ${SOURCE_FILES} Snake.cpp)


