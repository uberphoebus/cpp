cmake_minimum_required(VERSION 3.11)

project(
  ModooCode
  VERSION 0.1
  DESCRIPTION "cmake project for ModooCode"
  LANGUAGES CXX)
  
add_executable (program main.cc foo.cc)
# target_compile_options(program PUBLIC -Wall -Wextra -Werror -Wpedantic)
target_include_directories(program PUBLIC ${CMAKE_SOURCE_DIR}/includes)