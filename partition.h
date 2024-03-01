#ifndef PARTITION_H

#define PARTITION_H

#include <vector>
#include <algorithm>
#include <random>

template <typename T>
inline std::pair<int, int> partition3(std::vector<T>& a, int left, int right) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(left, right);

    int pivotIndex = distr(gen);
    T pivot = a[pivotIndex];
    std::swap(a[left], a[pivotIndex]);

    int i = left + 1;

    while (i <= right) {
        if (a[i] < pivot) {
            std::swap(a[i], a[left]);
            left++;
            i++;
        }
        else if (a[i] > pivot) {
            std::swap(a[i], a[right]);
            right--;
        }
        else {
            i++;
        }
    }

    return { left, right };
}


#endif