cmake_minimum_required(VERSION 3.5)

include(${CMAKE_CURRENT_SOURCE_DIR}/../config.cmake)

project(standards)

add_library(${PROJECT_NAME} INTERFACE)
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/public")
