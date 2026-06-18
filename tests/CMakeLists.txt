cmake_minimum_required(VERSION 4.0)
project(spryx)

set(CMAKE_CXX_STANDARD 20)

add_library(spryx STATIC library.cpp
        include/spryx/rnea.h
)
