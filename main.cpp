#include <iostream>
#include "Optional.h"


void testFilter() {

    Optional<int> test(1);

    Optional<int> result = test.filter([](int value) -> bool {
            return value < 10;
    });

    if (result.isPresent())
        std::cout << "Filter test result: " << result.getValue() << "\n";

}

void testIfPresent() {
    Optional<int> test(1);

    test.ifPresent([](int value) {
        std::cout << "ifPresent test result: " << value << "\n";

    });

}

void testMap() {
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

}

void testOrElse() {
    Optional<int> value2;

    auto result = value2.orElse(2);
    std::cout <<"Test orElse result: " << result << "\n";

}

void testOrElseGet() {
    Optional<int> value2;
    auto result2 = value2.orElseGet([]()->float {
        return 11.11;
    });

    std::cout <<"Test orElseGet result: " << result2 << "\n";
}


int main() {

    testMap();

    testFilter();

    testIfPresent();

    testOrElse();

    testOrElseGet();

    return 0;
}