cmake_minimum_required(VERSION 3.16)
project(sudoku)
set(CMAKE_CXX_STANDARD 17)

add_executable(sudoku main.cpp Node.cpp Node.h Column.cpp Column.h Cell.cpp Cell.h)
