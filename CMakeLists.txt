cmake_minimum_required(VERSION 3.5)

project(log_test)

macro(glob_sources sources_var sources_path)
    file(GLOB_RECURSE ${sources_var} ${sources_path}/*.h ${sources_path}/*.c
        ${sources_path}/*.cc ${sources_path}/*.cpp ${sources_path}/*.cxx)
endmacro()

glob_sources(FILE_SOURCES ./src)
add_executable(log_test  ${FILE_SOURCES})
target_include_directories(log_test PUBLIC ./src ./src/log)