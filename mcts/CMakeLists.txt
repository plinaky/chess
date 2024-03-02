cmake_minimum_required(VERSION 3.5)

include(${CMAKE_CURRENT_SOURCE_DIR}/../config.cmake)

project(mcts)

set(SOURCES
	tree.c
	mapper.c
	compare.c
	select.c
	)

add_library(${PROJECT_NAME} STATIC ${SOURCES})
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC  "${CMAKE_CURRENT_SOURCE_DIR}/public")
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/private")
target_link_libraries(${PROJECT_NAME} PRIVATE
	standards::standards
	chessrules::chessrules
	moves::moves
	)
