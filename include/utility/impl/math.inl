//
// Created by aiosadchy on 29/09/2019.
//

#ifndef SECS_MATH_INL
#define SECS_MATH_INL

#include "../math.hpp"

template <typename T>
T next_power_of_two(T x) {
    T result(1);
    while (result <= x) {
        result *= 2;
    }
    return result;
}

#endif // SECS_MATH_INL
