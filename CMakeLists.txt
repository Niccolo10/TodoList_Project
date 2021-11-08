cmake_minimum_required(VERSION 3.12)
project(TodoList_Project)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(test)

set (SOURCE_FILES Date.cpp Date.h Event.cpp Event.h List.cpp List.h ListOfLists.cpp ListOfLists.h)

add_executable(TodoList_Project main.cpp)

add_library(core ${SOURCE_FILES})

target_link_libraries(TodoList_Project core)