cmake_minimum_required(VERSION 3.22)
project(33_1)

set(CMAKE_CXX_STANDARD 14)

add_executable(33_1 src/main.cpp include/Stores.h src/Stores.cpp include/MyExceptions.h src/MyExceptions.cpp)
target_include_directories(33_1 PUBLIC include)
