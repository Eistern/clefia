cmake_minimum_required(VERSION 3.17)
project(clefia C)

set(CMAKE_C_STANDARD 11)

add_library(clefia SHARED clefia.c clefia.h)

add_executable(clefia_codec codec.c)
target_include_directories(clefia_codec PUBLIC .)
target_link_libraries(clefia_codec clefia)

add_executable(clefia_hash hash.c)
target_include_directories(clefia_hash PUBLIC .)
target_link_libraries(clefia_hash clefia)