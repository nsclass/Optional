cmake_minimum_required(VERSION 3.8)

project(LibOptional VERSION 0.1 LANGUAGES CXX)

add_library(LibOptional INTERFACE)

target_compile_features(LibOptional INTERFACE cxx_std_17)

# Define headers for this library. PUBLIC headers are used for
# compiling the library, and will be added to consumers' build
# paths.
target_include_directories(LibOptional
        INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)

enable_testing ()

add_subdirectory(test)