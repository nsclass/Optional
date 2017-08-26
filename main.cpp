#include <iostream>
#include "Optional.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    Optional<int> value(1);

    auto floatValue = value.map([](int value) -> float {
        return value * 10.0f;
    });

    std::cout << "floatValue: " << floatValue.getValue() << "\n";

    auto stringValue = floatValue.map([](float value) -> std::string {
        return std::to_string(value);
    });

    std::cout << "stringValue: " << stringValue.getValue() << "\n";

    auto finalValue = stringValue.map([](std::string const& value) -> int {
        return std::stoi(value);
    }).map([](int value) -> double {
        return (double)value;
    }).map([](double value) -> std::string {
        std::to_string(value);
    });

    std::cout << "finalValue: " << stringValue.getValue() << "\n";

    return 0;
}