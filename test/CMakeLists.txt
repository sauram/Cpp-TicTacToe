file(GLOB TESTS "*.cpp")

include_directories(./../include/)
# Add the executable
add_executable(tictactoe-test ${TESTS})

add_test(NAME tictactoe-test COMMAND tictactoe-test)

target_link_libraries(tictactoe-test PUBLIC tictactoe-static gtest gmock)
