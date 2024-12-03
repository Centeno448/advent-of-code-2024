add_executable(2day)

set(DAY2_INPUT_FILE "${CMAKE_CURRENT_SOURCE_DIR}/2day.txt")
set(DAY2_TEST_INPUT_FILE "${CMAKE_CURRENT_SOURCE_DIR}/2day.test.txt")

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/2day.in.h ${CMAKE_CURRENT_BINARY_DIR}/2day.h @ONLY)

target_include_directories(2day PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

target_sources(2day
    PRIVATE
        2day.cpp
        2day.h
)
