#ifndef QUICK_SORT_H

#define QUICK_SORT_H

#include <vector>

#include "partition.h"


template <typename T>
inline void quick_sort3(std::vector<T>& a, int left, int right) {
	if (left < right) {
		int k = (left + right) / 2;
		std::swap(a[left], a[k]);

		auto [lower, upper] = partition3(a, left, right);
		quick_sort3(a, left, lower - 1);
		quick_sort3(a, upper + 1, right);
	}
}


template <typename T>
inline void quick_sort3(std::vector<T>& a) {
	quick_sort3(a, 0, a.size() - 1);
}


#endif
