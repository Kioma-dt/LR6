cmake_minimum_required(VERSION 3.28)
project("MyProject")
set(CMAKE_CXX_STANDART 20)

add_executable(main main.cpp Functions.cpp Functions.h Tasks.cpp Tasks.h)
