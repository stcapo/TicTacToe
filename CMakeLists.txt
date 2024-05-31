cmake_minimum_required(VERSION 3.10)
project(TicTacToe)

set(CMAKE_CXX_STANDARD 11)

# Include header files
include_directories(src)

# Add the executable
add_executable(TicTacToe src/main.cpp src/game.cpp)
