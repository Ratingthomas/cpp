cmake_minimum_required(VERSION 3.27)
project(WC_Week_4)

set(CMAKE_CXX_STANDARD 20)

add_executable(WC_Week_4 main.cpp
        Options.cpp
        Options.h
        FileCounts.h
        Counter.cpp
        Counter.h
)
