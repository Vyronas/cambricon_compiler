cmake_minimum_required(VERSION 3.13)
project(cambricon_compiler)

set(CMAKE_CXX_STANDARD 17)

add_executable(cambricon_compiler compiler.cpp Variable.cpp Variable.h)