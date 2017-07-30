cmake_minimum_required(VERSION 3.8.2)

project(schoolhouse LANGUAGES CXX)

enable_testing()

set(CMAKE_CXX_STANDARD 17)

# Used by YouCompleteMe (https://github.com/Valloric/YouCompleteMe#c-family-semantic-completion)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Each schoolhouse course (book, etc) is a subproject
#
add_subdirectory(pppcpp)
