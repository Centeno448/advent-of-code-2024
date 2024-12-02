cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED ON)

project(advent-of-code-2024 VERSION 1.0)

option(USE_TEST_INPUTS "If should use the test.txt files instead of the actual inputs" OFF)

add_subdirectory(1day)
