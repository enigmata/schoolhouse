project(city_distances LANGUAGES CXX)

# The solution to the exercise is ecapsulated in an object file
# to be included in a cli for interactive use, and test driver
#
add_library(city_dist OBJECT city_dist.cpp)

# CLI (Command-line Interface) for interactively playing with the 
# solution to the exercise
add_executable(city_dist_cli cli.cpp $<TARGET_OBJECTS:city_dist>)

# Unit test driver
add_executable(city_dist_test test.cpp $<TARGET_OBJECTS:city_dist>)
target_link_libraries(city_dist_test test_catch_main)
target_include_directories(city_dist_test PUBLIC ${TEST_CATCH_INCLUDE_DIR})
add_test(pppcpp-chp04-03-city_dist_test city_dist_test)
