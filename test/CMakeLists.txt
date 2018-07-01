set(CMAKE_CXX_STANDARD 17)

add_executable(OptionalTest src/test_main.cpp)

# Define the libraries this project depends upon
target_link_libraries(OptionalTest
        PRIVATE
        LibOptional)
