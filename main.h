#ifndef LIB_STD_NUM_MAIN_H
#define LIB_STD_NUM_MAIN_H

#include <cmath>
#include <random>
#include <vector>
#include <algorithm>
#include <chrono>

namespace stdnum {

template<class C1, class C2>
double l2sqdiff(const C1& a, const C2& b) {

    const auto& a_end = a.end();
    const auto& b_end = b.end();

    double sum = 0;
    auto a_it = a.begin();
    auto b_it = b.begin();

    for (; a_it != a_end && b_it != b_end; ++a_it, ++b_it) {
        const double diff = (*a_it) - (*b_it);
        sum += diff * diff;
    }

    return sum;
}

template<class C1, class C2>
double l2diff(const C1& a, const C2& b) {
    return std::sqrt(l2sqdiff(a,b));
}


template<class Integer>
std::vector<size_t> shuffling(const Integer size) {
    std::vector<size_t> result;
    result.reserve(size);
    for (size_t ii = 0; ii < size; ++ii) {
        result.push_back(ii);
    }
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    std::shuffle(result.begin(), result.end(), std::default_random_engine(seed));
    return result;
}

template<class T>
std::vector<size_t> shuffling(const std::vector<T>& c) {
    return shuffling(c.size());
}

template<class C>
bool is_weakly_decreasing(const C& container) {
    if (container.empty() || container.size() < 2) {
        return true;
    }
    double last = container.front();
    for (const auto val : container) {
        if (val > last) {
            return false;
        }
        last = val;
    }
    return true;
}


} // namespace stdnum

#endif // LIB_STD_NUM_MAIN_H
