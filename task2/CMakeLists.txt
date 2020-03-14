cmake_minimum_required(VERSION 2.8)

project(tp)

execute_process(COMMAND python3 ${CMAKE_CURRENT_SOURCE_DIR}/A/preparing.py
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/A)

add_subdirectory(B)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}")	

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

add_executable(C ${CMAKE_CURRENT_SOURCE_DIR}/C/main.cpp)

target_link_libraries(C lib)


install(TARGETS C DESTINATION bin)
