cmake_minimum_required(VERSION 3.17)
project(oop_lab1)

set(CMAKE_CXX_STANDARD 14)

add_executable(oop_lab1
        main.cpp Date.cpp Event.cpp Event.h Time.cpp Time.h SortingStrategy.h)
