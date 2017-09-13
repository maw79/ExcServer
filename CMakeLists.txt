cmake_minimum_required(VERSION 3.8)
project(untitled)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/main.cpp src/Customer.cpp src/Customer.h src/Date.cpp src/Date.h src/Credit.cpp src/Credit.h src/Product.cpp src/Product.h src/CustomerList.cpp src/CustomerList.h src/Menu.cpp src/Menu.h)
add_executable(untitled ${SOURCE_FILES})