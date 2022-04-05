cmake_minimum_required(VERSION 3.21)
project(cpp_practice)

add_subdirectory(algorithm)

set(CMAKE_CXX_STANDARD 11)

add_executable(cpp_practice main.cpp)
add_executable(placement_new placement_new.cpp)
add_executable(move move.cpp)
add_executable(open_nvm_file_test open_nvm_file_test.cpp)
