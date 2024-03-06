// include/utils.hpp
#pragma once
#include <iostream>

namespace util {

template <typename T>
void printArray(const T *arr, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

} // namespace util
