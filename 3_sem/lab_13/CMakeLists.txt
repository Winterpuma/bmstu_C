cmake_minimum_required(VERSION 3.12)
project(lab_13 C)

set(CMAKE_C_STANDARD 99)

add_executable(lab_13 main.c my_list.c my_list.h structures.c structures.h input.c input.h)

add_executable(lab_13_test test.c test.h my_list.c my_list.h structures.c structures.h input.c input.h)