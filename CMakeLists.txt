cmake_minimum_required(VERSION 3.26)
project(untitled1 C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled1 main.c)
add_executable(project10
        guest.h
        guest.c
        read_line.h
        read_line.c
        project10_guests.c
        makefile)
