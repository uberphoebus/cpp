add_library(shape STATIC shape.cc) # static library

target_include_directories(shape PUBLIC ${CMAKE_SOURCE_DIR}/includes)

target_compile_options(shape PRIVATE -Wall -Werror)

target_link_libraries(shape PRIVATE pthread)