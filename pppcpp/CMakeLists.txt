project(pppcpp LANGUAGES CXX)

# Ensure child projects can access the test include directory
#
set(TEST_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/test)

# Unit testing library used by all subprojects
#
add_subdirectory(test)

# Each chapter of the book is a subproject
#
add_subdirectory(chp04)
