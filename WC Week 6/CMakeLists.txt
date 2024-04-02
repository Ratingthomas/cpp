cmake_minimum_required(VERSION 3.27)
project(WC_Week_6)

set(CMAKE_CXX_STANDARD 20)

add_executable(WC_Week_6 main.cpp
        String.cpp
        String.h)

target_compile_options(WC_Week_6 PRIVATE -Wall -Wextra -pedantic -fsanitize=address -fno-omit-frame-pointer)
target_link_options(WC_Week_6 PRIVATE -fsanitize=address)
