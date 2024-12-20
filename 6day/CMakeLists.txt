add_executable(6day)

set(DAY6_INPUT_FILE "${CMAKE_CURRENT_SOURCE_DIR}/6day.txt")
set(DAY6_TEST_INPUT_FILE "${CMAKE_CURRENT_SOURCE_DIR}/6day.test.txt")

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/6day.in.h ${CMAKE_CURRENT_BINARY_DIR}/6day.h @ONLY)

target_include_directories(6day PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

target_sources(6day
    PRIVATE
        6day.cpp
        6day.h
)
