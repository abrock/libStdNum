#ifndef LIB_STD_NUM_MAIN_H
#define LIB_STD_NUM_MAIN_H

#include <cmath>

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

} // namespace stdnum

#endif // LIB_STD_NUM_MAIN_H
