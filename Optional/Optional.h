//
// Created by Nam Seob Seo on 8/21/17.
//

#ifndef MONAD_TEST_OPTIONAL_H
#define MONAD_TEST_OPTIONAL_H


#include <type_traits>

namespace NS {

    template<class T>
    class Optional {
    private:
        T value;
        bool hasValue;

    public:
        Optional() : hasValue(false) {

        }

        Optional(T value) : value(value), hasValue(true) {

        }

    public:
        T getValue() const {
            return value;
        }

        bool isPresent() const {
            return hasValue;
        }

    public:
        template<class F>
        auto map(F &&f) -> Optional<std::decay_t<decltype(f(value))>> {
            if (hasValue) {
                return f(value);
            }

            return decltype(f(value))();
        }

        auto orElse(T other) {
            if (hasValue)
                return value;

            return other;
        }

        template<class F>
        T orElseGet(F &&f) {
            if (hasValue)
                return value;

            return f();
        }

        template<class F>
        void ifPresent(F &&f) {
            if (hasValue) {
                f(value);
            }
        }

        template<class F>
        auto filter(F &&f) {
            if (hasValue && f(value)) {
                return Optional<T>(value);
            }

            return Optional<T>();
        }

    };

}


#endif //MONAD_TEST_OPTIONAL_H
