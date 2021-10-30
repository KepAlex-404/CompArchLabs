cmake_minimum_required(VERSION 3.20)
project(cpp)


include(FindPkgConfig)
pkg_check_modules(CURLPP REQUIRED curlpp)

target_link_libraries(mylibcurlppprog ${CURLPP_LDFLAGS})

set(CMAKE_CXX_STANDARD 14)

add_executable(cpp main.cpp)
