cmake_minimum_required(VERSION 3.8)
project(monad_test)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main/main.cpp Optional/Optional.h)
add_executable(monad_test ${SOURCE_FILES})