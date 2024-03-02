cmake_minimum_required(VERSION 3.5)

include(${CMAKE_CURRENT_SOURCE_DIR}/../../config.cmake)

project(moves)

set(SOURCES
	pawn.c
	king.c
	knight.c
	brq.c
	move.c
	)

add_library(${PROJECT_NAME} STATIC ${SOURCES})
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/public")

target_link_libraries(${PROJECT_NAME} PRIVATE
	standards::standards
	chessrules::chessrules
	)
