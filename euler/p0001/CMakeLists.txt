project(p0001 LANGUAGES CXX)

# The solution to the exercise is ecapsulated in an object file
# to be included in a cli for interactive use, and test driver
#
add_library(multiples_of OBJECT multiples_of.cpp)

# CLI (Command-line Interface) for interactively playing with the 
# solution to the exercise
add_executable(multiples_of_cli cli.cpp $<TARGET_OBJECTS:multiples_of>)

# Unit test driver
add_executable(multiples_of_test test.cpp $<TARGET_OBJECTS:multiples_of>)
target_link_libraries(multiples_of_test test_catch_main)
target_include_directories(multiples_of_test PUBLIC ${TEST_CATCH_INCLUDE_DIR})
add_test(euler-0002-multiples_of_test multiples_of_test)
