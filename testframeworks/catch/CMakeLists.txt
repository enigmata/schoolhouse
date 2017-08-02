
include_directories(${TEST_CATCH_LOCAL_INCLUDE_DIR})

# Unit testing lib required by all projects testing via Catch
#
add_library(test_catch_main STATIC test_main.cpp)
