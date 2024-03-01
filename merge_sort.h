#ifndef MERGE_SORT_H

#define MERGE_SORT_H

#include <vector>

#include "merge.h"

template <typename T>
inline std::vector<T> merge_sort(std::vector<T>& a, int left, int right) {
	if (left >= right) {
		return { a[left] };
	}

	int m = (left + right) / 2;
	std::vector<T> left_part = merge_sort(a, left, m);
	std::vector<T> right_part = merge_sort(a, m + 1, right);

	return merge(left_part, right_part);
}

template <typename T>
inline void merge_sort(std::vector<T>& a) {
	std::vector<T> sorted_a = merge_sort(a, 0, a.size() - 1);
	a.swap(sorted_a);
}

#endif