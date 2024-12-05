add_executable(4day)

set(DAY4_INPUT_FILE "${CMAKE_CURRENT_SOURCE_DIR}/4day.txt")
set(DAY4_TEST_INPUT_FILE "${CMAKE_CURRENT_SOURCE_DIR}/4day.test.txt")

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/4day.in.h ${CMAKE_CURRENT_BINARY_DIR}/4day.h @ONLY)

target_include_directories(4day PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

target_sources(4day
    PRIVATE
        4day.cpp
        4day.h
)
