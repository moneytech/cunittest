cmake_minimum_required(VERSION 3.5)
project(libfoo-test)

add_executable(libfoo-test libfoo-test.c)

include_directories(.. ../../..)


target_link_libraries(libfoo-test PUBLIC foo)