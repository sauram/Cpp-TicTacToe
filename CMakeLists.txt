cmake_minimum_required(VERSION 3.16.3)
project(tictactoe)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)

option(BUILD_TESTS "Turn on build for tests" OFF)

# Add the source files
file(GLOB SOURCES "src/*.cpp")

# Set include files
set(INCLUDES include/)

if(BUILD_TESTS)
    # Add the test files
    add_subdirectory(test)
endif()

include_directories(${INCLUDES})

# Add the executable
add_executable(tictactoe ${SOURCES})