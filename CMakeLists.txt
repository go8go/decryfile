cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(hello-world LANGUAGES CXX)

add_executable(
    ${PROJECT_NAME}
    decry.cpp
)
