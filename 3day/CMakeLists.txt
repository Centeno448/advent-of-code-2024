add_executable(3day)

set(DAY3_INPUT_FILE "${CMAKE_CURRENT_SOURCE_DIR}/3day.txt")
set(DAY3_TEST_INPUT_FILE "${CMAKE_CURRENT_SOURCE_DIR}/3day.test.txt")

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/3day.in.h ${CMAKE_CURRENT_BINARY_DIR}/3day.h @ONLY)

target_include_directories(3day PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

target_sources(3day
    PRIVATE
        3day.cpp
        3day.h
)
