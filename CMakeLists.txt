cmake_minimum_required(VERSION 3.5)

# mkdir build && cd build && rm -Rf * && cmake -G Ninja -DRELEASE=ON .. && ninja
# mkdir build && cd build && rm -Rf * && cmake -DRELEASE=OFF .. && make

include(${CMAKE_CURRENT_SOURCE_DIR}/config.cmake)

project(chess)

option(RELEASE "Activer les drapeaux d'optimisation" ON)

add_subdirectory(mcts EXCLUDE_FROM_ALL)
add_subdirectory(chessrules EXCLUDE_FROM_ALL)
add_subdirectory(standards EXCLUDE_FROM_ALL)

set(SOURCES
	chess.c
	)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE
	mcts::mcts
	chessrules::chessrules
	standards::standards
	)
