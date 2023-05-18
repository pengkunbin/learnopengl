cmake_minimum_required(VERSION 3.26)

include_directories("/usr/local/include")

add_library(glad /usr/local/lib/glad.c)

find_package(glfw3 REQUIRED)

project(learnopengl)
add_executable(learnopengl main.cpp)

target_link_libraries(learnopengl glad)
target_link_libraries(learnopengl glfw)
