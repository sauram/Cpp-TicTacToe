cmake_minimum_required(VERSION 3.16.3)
project(tictactoe)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_TESTS "Turn on build for tests" OFF)

# Add the source files
file(GLOB SOURCES "src/*.cpp")

# Set include files
set(INCLUDES include/)

if(BUILD_TESTS)
    # Add the test files
    set(BUILD_GMOCK ON)
    add_subdirectory(external/googletest)
    add_subdirectory(test)
endif()

include_directories(${INCLUDES})

# Add the executable
add_executable(tictactoe ${SOURCES})

add_library(tictactoe-static STATIC ${SOURCES})