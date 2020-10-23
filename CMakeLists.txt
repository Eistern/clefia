cmake_minimum_required(VERSION 3.17)
project(clefia C)

set(CMAKE_C_STANDARD 11)

add_executable(clefia clefia.c codec.c clefia.h)

add_executable(clefia_test test_impl.c)

add_executable(clefia_hash clefia.h clefia.c hash.c)