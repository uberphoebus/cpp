cmake_minimum_required(VERSION 3.11)

project(
  ModooCode
  VERSION 0.1.0
  LANGUAGES CXX
)

add_subdirectory(lib)

add_executable(program main.cc)

target_link_libraries(program shape)