project(pppcpp LANGUAGES CXX)

# Ensure child projects can access the test include directory
#
set(TEST_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/test)
set(TEST_OBJ_FILES ${CMAKE_CURRENT_SOURCE_DIR}/test/test_main.o)

# # Unit testing object code used by all subprojects
# #
# add_library(test_main OBJECT test/test_main.cpp)
# set(TEST_OBJ ${CMAKE_CURRENT_SOURCE_DIR}/test/test_main.o)
add_subdirectory(test)

# Each chapter of the book is a subproject
#
add_subdirectory(chp04)
