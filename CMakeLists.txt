cmake_minimum_required(VERSION 3.12)
project(TodoList_Project)

set(CMAKE_CXX_STANDARD 14)

add_executable(TodoList_Project main.cpp Date.cpp Date.h Event.cpp Event.h List.cpp List.h)