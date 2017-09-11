# Nothing to build for now, but some configuration is required:

# All testframeworks currently supported for the schoolhouse
#
# Catch @ http://catch-lib.net
find_path(TEST_CATCH_LOCAL_INCLUDE_DIR catch.hpp ${CMAKE_CURRENT_SOURCE_DIR}/catch/catch.git/single_include)
if ((NOT TEST_CATCH_LOCAL_INCLUDE_DIR) OR (NOT EXISTS ${TEST_CATCH_LOCAL_INCLUDE_DIR}))
    message("Cloning the catch git repo as a submodule")
    execute_process(COMMAND git submodule update --init testframeworks/catch/catch.git WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
    set(TEST_CATCH_LOCAL_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/catch/catch.git/single_include)
endif()
set(TEST_CATCH_INCLUDE_DIR ${TEST_CATCH_LOCAL_INCLUDE_DIR} PARENT_SCOPE) # push up to all projects
add_subdirectory(catch)
