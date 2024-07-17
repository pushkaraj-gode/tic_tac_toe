cmake_minimum_required(VERSION 3.8)
project(tic_tac_toe)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/src)
set(SOURCES
    ${CMAKE_SOURCE_DIR}/src/main.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

if(UNIX)
    target_link_libraries(${PROJECT_NAME} pthread)
endif()