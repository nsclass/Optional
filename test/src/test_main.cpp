#include <iostream>
#include "Optional.h"

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

using namespace NS;


auto testFilter() {

    Optional<int> test(1);

    Optional<int> result = test.filter([](int value) -> bool {
            return value < 10;
    });

    return result;

}


TEST_CASE( "1: Filter test", "Optional" ) {
    REQUIRE(testFilter().getValue() == 1);
}


TEST_CASE( "2: ifPresent test", "Optional" ) {
    Optional<int> test(1);

    test.ifPresent([](int value) {
        REQUIRE(testFilter().getValue() == 1);
    });
}


TEST_CASE( "3: map test", "Optional" ) {
    Optional<int> value(1);

    auto floatValue = value.map([](int value) -> float {
        return value * 10.1f;
    });

    REQUIRE(floatValue.getValue() == 10.1f);

    auto stringValue = floatValue.map([](float value) -> std::string {
        return std::to_string((int)value);
    });


    REQUIRE(stringValue.getValue() == "10");

    auto finalValue = stringValue.map([](std::string const& value) -> int {
        return std::stoi(value);
    }).map([](int value) -> double {
        return (double)value + 10;
    }).map([](double value) -> std::string {
        return std::to_string((int)value);
    });

    REQUIRE(finalValue.getValue() == "20");
}

TEST_CASE( "4: orElse test integer", "Optional" ) {
    Optional<int> value2;

    Optional<int> result = value2.orElse(2);
    REQUIRE(result.getValue() == 2);

}

TEST_CASE( "5: orElse test float", "Optional" ) {
    Optional<int> value2;
    Optional<int> result2 = value2.orElseGet([]()-> int {
        return 11;
    });
    REQUIRE(result2.getValue() == 11);
}
