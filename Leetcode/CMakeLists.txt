cmake_minimum_required(VERSION 3.20)

project(Leetcode C CXX)

#SET(CMAKE_C_COMPILER C:/msys64/ucrt64/bin/gcc.exe)
#SET(CMAKE_CXX_COMPILER C:/msys64/ucrt64/bin/g++.exe)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if (WIN32)
    set(CMAKE_FIND_LIBRARY_SUFFIXES ".lib;.a;${CMAKE_FIND_LIBRARY_SUFFIXES}")
else()
# BUGGY!
#    set(CMAKE_FIND_LIBRARY_SUFFIXES ".a;${CMAKE_FIND_LIBRARY_SUFFIXES}")
endif()

set(Boost_USE_STATIC_LIBS ON)
set(LINK_SEARCH_START_STATIC ON)
#set(LINK_SEARCH_END_STATIC ON)
set(BUILD_SHARED_LIBS OFF)
# set(CMAKE_EXE_LINKER_FLAGS "-static")

#file(GLOB lessons LIST_DIRECTORIES true "l[1-9]")
add_subdirectory(Contains_Duplicate_217)
add_subdirectory(Valid_Anagram_242)
add_subdirectory(Product_Of_Array_Except_Self_238)
add_subdirectory(Valid_Sudoku_36)
add_subdirectory(Encode_And_Decode_Strings_271)