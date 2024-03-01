#ifndef TESTS_H

#define TESTS_H

#include <iostream>
#include <vector>

#include "merge_sort.h"
#include "quick_sort.h"
#include "bubble_sort.h"


template <typename T>
inline bool is_sorted(const std::vector<T>& a) {
    for (size_t i = 1; i < a.size(); ++i) {
        if (a[i] < a[i - 1]) {
            return false;
        }
    }
    return true;
}

template <typename T>
inline void test_sort(const std::string& name, void (*sort)(std::vector<T>&)) {
    std::cout << "Testing " << name << " in progress..." << std::endl;

    std::vector<int> a = { 5, 2, 4, 6, 1, 3 };
    sort(a);
    if (!is_sorted(a)) {
        std::cout << "Test failed: {5, 2, 4, 6, 1, 3}" << std::endl;
    }

    std::vector<int> b = { 1, 2, 3, 4, 5, 6 };
    sort(b);
    if (!is_sorted(b)) {
        std::cout << "Test failed: {1, 2, 3, 4, 5, 6}" << std::endl;
    }

    std::vector<int> c = { 6, 5, 4, 3, 2, 1 };
    sort(c);
    if (!is_sorted(c)) {
        std::cout << "Test failed: {6, 5, 4, 3, 2, 1}" << std::endl;
    }

    std::vector<int> d = { 1 };
    sort(d);
    if (!is_sorted(d)) {
        std::cout << "Test failed: {1}" << std::endl;
    }

    std::cout << "Testing is over." << std::endl;
}

inline int run_tests() {
    test_sort<int>("merge sort", merge_sort);
    test_sort<int>("quick sort", quick_sort3);
    test_sort<int>("bubble_sort", bubble_sort);

    return 0;
}


#endif
