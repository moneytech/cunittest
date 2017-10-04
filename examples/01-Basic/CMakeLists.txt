cmake_minimum_required(VERSION 3.5)
project(libfoo)

set(foo_src foo.c)

add_subdirectory(test)

add_library(foo ${foo_src})
