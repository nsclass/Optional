//
// Created by Nam Seob Seo on 8/21/17.
//

#ifndef MONAD_TEST_OPTIONAL_H
#define MONAD_TEST_OPTIONAL_H


#include <type_traits>

template <class T>
class Optional {
private:
    T value;
    bool hasValue;

public:
    Optional(T value) : value(value), hasValue(true) {

    }

public:
    T getValue() const {
        return value;
    }

public:
    template<class F>
    auto map(F&& f) -> Optional<std::decay_t<decltype(f(value))>> {
        if (hasValue) {
            return f(value);
        }

        return decltype(f(value))();
    }

};


#endif //MONAD_TEST_OPTIONAL_H
