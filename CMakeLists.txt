cmake_minimum_required(VERSION 3.8.2)

project(schoolhouse LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

# Each schoolhouse course (book, etc) is a subproject
#
add_subdirectory(pppcpp)
