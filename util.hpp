#pragma once
#include <array>
#include <vector>
#include <iostream>
#include "Vector.hpp"


namespace og {

    int randint(int start, int end);

    long long randlong(long long start, long long end);

    template<typename T, std::size_t size>
    const T& rand_choice(const std::array<T, size>& arr) {
        return arr[og::randint(0, size - 1)];
    }

    template<typename T>
    const T& rand_choice(const std::vector<T>& v) {
        return v[og::randint(0, v.size() - 1)];
    }

    template<typename T, std::size_t size>
    const T* rand_choice(const T* arr) {
        return arr + og::randint(0, size - 1);
    }

    template<typename T>
    void print_vec(const og::Vector2<T>& v) {
        std::cout << "Vec(" << v.x << ',' << ' ' << v.y << ')' << '\n';
    }

}