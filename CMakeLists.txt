cmake_minimum_required(VERSION 3.8.2)

project(schoolhouse LANGUAGES CXX)

enable_testing()

set(CMAKE_CXX_STANDARD 17)

# Test frameworks
#
add_subdirectory(testframeworks)

# Each schoolhouse course (book, etc) is a subproject
#
add_subdirectory(pppcpp)
add_subdirectory(euler)
