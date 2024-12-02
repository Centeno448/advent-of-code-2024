add_executable(1day)

if(USE_TEST_INPUTS)
    set(DAY1_INPUT_FILE "${CMAKE_CURRENT_SOURCE_DIR}/1day.test.txt")
else()
    set(DAY1_INPUT_FILE "${CMAKE_CURRENT_SOURCE_DIR}/1day.txt")
endif()

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/1day.in.h ${CMAKE_CURRENT_BINARY_DIR}/1day.h @ONLY)

target_include_directories(1day PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

target_sources(1day
    PRIVATE
        1day.cpp
        1day.h
)
