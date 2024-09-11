cmake_minimum_required(VERSION 3.16.3)

set(CMAKE_CXX_STANDARD 11)

file(GLOB TESTS "*.cpp")

# Add the executable
add_executable(tests ${TESTS})

