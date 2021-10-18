cmake_minimum_required(VERSION 3.20)
project(cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(cpp Hotel.cpp Hotel.h Hotel.cpp HotelTest.cpp Database.h Database.cpp)
