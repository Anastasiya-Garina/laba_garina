#ifndef MERGE_H 

#define MERGE_H

#include <vector>
#include <algorithm>

template <typename T>
inline std::vector<T> merge(const std::vector<T>& a, const std::vector<T>& b) {
	std::vector<T> res;
	auto i = a.begin();
	auto j = b.begin();

	while (i != a.end() && j != b.end()) {
		if (*i <= *j) {
			res.push_back(*i);
			++i;
		}
		else {
			res.push_back(*j);
			++j;
		}
	}

	while (i != a.end()) {
		res.push_back(*i);
		++i;
	}

	while (j != b.end()) {
		res.push_back(*j);
		++j;
	}

	return res;
}

#endif