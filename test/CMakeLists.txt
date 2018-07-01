
add_executable(OptionalTest src/test_main.cpp)

target_compile_features(OptionalTest PRIVATE cxx_std_17)

# Define the libraries this project depends upon
target_link_libraries(OptionalTest
            LibOptional)
