#ifndef BUBBLE_SORT_H 

#define BUBBLE_SORT_H

#include <vector>
#include <algorithm>

template <typename T>
inline void bubble_sort(std::vector<T>& a) {
	int n = a.size();

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n - i - 1; ++j) {
			if (a[j] > a[j + 1]) {
				std::swap(a[j], a[j + 1]);
			}
		}
	}
}

#endif

