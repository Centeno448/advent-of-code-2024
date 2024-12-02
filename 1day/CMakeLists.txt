add_executable(1day)

set(DAY1_INPUT_FILE "${CMAKE_CURRENT_SOURCE_DIR}/1day.txt")
set(DAY1_TEST_INPUT_FILE "${CMAKE_CURRENT_SOURCE_DIR}/1day.test.txt")

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/1day.in.h ${CMAKE_CURRENT_BINARY_DIR}/1day.h @ONLY)

target_include_directories(1day PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

target_sources(1day
    PRIVATE
        1day.cpp
        1day.h
)
