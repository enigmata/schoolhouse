# Nothing to build for now, but some configuration is required:

# All testframeworks currently supported for the schoolhouse
#
# Catch @ http://catch-lib.net
set(TEST_CATCH_LOCAL_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/catch/catch.git/single_include)
set(TEST_CATCH_INCLUDE_DIR ${TEST_CATCH_LOCAL_INCLUDE_DIR} PARENT_SCOPE) # push up to all projects
add_subdirectory(catch)
