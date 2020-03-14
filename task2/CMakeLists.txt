cmake_minimum_required(VERSION 3.0)

project(tp)

execute_process(COMMAND python3 ${CMAKE_CURRENT_SOURCE_DIR}/A/preparing.py
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/A)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/B)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}")	

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

add_executable(C ${CMAKE_CURRENT_SOURCE_DIR}/C/main.cpp)

target_link_libraries(C lib)
configure_file("${CMAKE_SOURCE_DIR}/C/path.h.in"
                 "${CMAKE_SOURCE_DIR}/C/path.h")
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/C/googletest)
enable_testing()


set(GTEST_INCLUDE_DIRS ${GTEST_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR}/C)
include_directories("${CMAKE_SOURCE_DIR}/A")
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(CTest ${CMAKE_CURRENT_SOURCE_DIR}/C/main_test.cpp ${CMAKE_CURRENT_SOURCE_DIR}/C/tests.cpp)
target_link_libraries(CTest gtest_main)

add_test( NAME AllTestsInCTest  COMMAND CTest)



install(TARGETS C DESTINATION bin)


