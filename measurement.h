#ifndef MEASUREMENT_H

#define MEASUREMENT_H

#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <fstream>

#include "merge_sort.h"
#include "quick_sort.h"
#include "bubble_sort.h"


template <typename T>
void measure_sort(const std::string& name, const std::vector<int>& sizes, void (*sort)(std::vector<T>&)) {
	std::cout << "Measure " << name << " in progress..." << std::endl;
		
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distr(INT_MIN, INT_MAX);

	std::ofstream file(name + ".csv");

	for (const auto& size : sizes) {
		std::vector<T> a(size);
		for (auto& item : a) {
			item = distr(gen);
		}

		auto start = std::chrono::high_resolution_clock::now();
		sort(a);
		auto end = std::chrono::high_resolution_clock::now();

		std::chrono::duration<double, std::milli> diff = end - start;
		std::cout << name << " sort time for " << size << " elements: " << diff.count() << " ms\n";
		file << size << "\t" << diff.count() << "\n";
	}

	file.close();

	std::cout << "Measure " << name << " is over" << std::endl;
}

int measure() {
	measure_sort<int>("merge_sort", { 10, 100, 1000, 10000, 100000, 1000000 }, merge_sort);
	measure_sort<int>("quick_sort3", { 10, 100, 1000, 10000, 100000, 1000000 }, quick_sort3);
	measure_sort<int>("bubble_sort", { 10, 100, 1000, 10000, 100000 }, bubble_sort);

	return 0;
}


#endif