cmake_minimum_required(VERSION 3.5)

project(uevm C)

set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 99)

add_executable(uevm src/uevm.c)
