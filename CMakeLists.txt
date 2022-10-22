cmake_minimum_required(VERSION 3.23)
project(tic_tac_toe_cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(tic_tac_toe_cpp main.cpp TicTacToe.cpp Board.cpp)
