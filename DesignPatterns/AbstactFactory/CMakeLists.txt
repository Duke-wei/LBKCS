cmake_minimum_required(VERSION 2.8)

project(AbstractFactory)
SET(CMAKE_C_COMPILER g++)
add_compile_options(-std=c++11)
add_executable(AbstractFactory main.cpp AbstractFactory.cpp Product.cpp)
