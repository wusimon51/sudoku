cmake_minimum_required(VERSION 3.16)
project(sudoku)
set(CMAKE_CXX_STANDARD 17)

add_executable(sudoku src/main.cpp src/Node.cpp src/Node.h src/Column.cpp src/Column.h src/Cell.cpp src/Cell.h)
