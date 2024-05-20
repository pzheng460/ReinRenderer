cmake_minimum_required(VERSION 3.28)
project(ReinRenderer)

set(CMAKE_CXX_STANDARD 17)

add_executable(ReinRenderer main.cpp
        tgaimage.cpp
        tgaimage.h)
