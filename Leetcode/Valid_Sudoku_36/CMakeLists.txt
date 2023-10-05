cmake_minimum_required(VERSION 3.20)

project(valid_sudoku_36)

set(${PROJECT_NAME}_SRC main.cpp)

source_group(source FILES ${${PROJECT_NAME}_SRC})

add_executable("${PROJECT_NAME}" "${${PROJECT_NAME}_SRC}")