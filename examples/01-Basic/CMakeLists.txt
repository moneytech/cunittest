cmake_minimum_required(VERSION 3.5)
project(libfoo)
enable_testing()

set(foo_src foo.c)

add_subdirectory(test)

add_library(foo ${foo_src})

add_test(NAME test_foo_multiply
COMMAND test/libfoo-test multiply)

add_test(NAME test_foo_multiply2
COMMAND test/libfoo-test multiply2)
