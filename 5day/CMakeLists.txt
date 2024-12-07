add_executable(5day)

set(DAY5_INPUT_FILE "${CMAKE_CURRENT_SOURCE_DIR}/5day.txt")
set(DAY5_TEST_INPUT_FILE "${CMAKE_CURRENT_SOURCE_DIR}/5day.test.txt")

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/5day.in.h ${CMAKE_CURRENT_BINARY_DIR}/5day.h @ONLY)

target_include_directories(5day PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

target_sources(5day
    PRIVATE
        5day.cpp
        5day.h
)
