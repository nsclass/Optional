
add_executable(OptionalTest src/test_main.cpp)

# Define the libraries this project depends upon
target_link_libraries(OptionalTest
            LibOptional
            Catch2)
