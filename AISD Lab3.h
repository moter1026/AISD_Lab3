#pragma once

#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <cstdlib>
#include <stdexcept>

using namespace std;

struct Stats {
	size_t comparison_count = 0;
	size_t copy_count = 0;
};

class ComparisonClass {
private:
	int _value;
public:

	ComparisonClass() : _value(0) {}

	ComparisonClass(int value) : _value(value) {}

	int get_value() const {
		return this->_value;
	}

	bool operator > (const ComparisonClass& rhs) const {
		return this->_value > rhs._value;
	}

	bool operator < (const ComparisonClass& rhs) const {
		return this->_value < rhs._value;
	}
};

template <typename T>
void custom_swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
void Print(vector<T> vec) {
	for (int i = 0; i < vec.size(); ++i)
		cout << vec[i] << " ";
	cout << "\n\n";
}

ostream& operator<<(std::ostream& os, Stats& stat)
{
	os << "comparison_count = " << stat.comparison_count << " copy_count = " << stat.copy_count;
	return os;
}

template<typename T>
Stats& InsertSort(vector<T>& vec) {
	Stats statistics;
	for (size_t i = 1; i < vec.size(); ++i) {
		T elem = vec.at(i);
		statistics.copy_count++;
		size_t j = i;

		while (j > 0 && vec.at(j - 1) > elem) {

			statistics.comparison_count++;
			vec.at(j) = vec.at(j - 1);
			--j;
			statistics.copy_count++;
		}

		statistics.comparison_count++;
		vec.at(j) = elem;
		statistics.copy_count++;
	}
	return statistics;
}

template <typename T>
Stats& ShakerSort(std::vector<T>& arr) {
	Stats s;
	size_t n = arr.size();
	size_t start = 0;
	size_t end = n - 1;
	bool swapped;
	while (n > 0) {
		swapped = false;
		for (size_t i = start; i < end; ++i) {
			s.comparison_count++;
			if (arr[i] > arr[i + 1]) {
				custom_swap(arr[i], arr[i + 1]);
				s.copy_count += 3;
				swapped = true;
			}
		}
		if (swapped == false) break;
		end--;
		n--;
		if (n <= 0) break;
		for (size_t i = end; i > start; --i) {
			s.comparison_count++;
			if (arr[i] < arr[i - 1]) {
				custom_swap(arr[i], arr[i - 1]);
				s.copy_count += 3;
				swapped = true;
			}
		}
		start++;
		n--;
		if (swapped == false) break;
	}

	return s;
}

template <typename T>
void Heapify(std::vector<T>& vec, int size, int i, Stats& statistics) {
	int max = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left < size) {
		statistics.comparison_count++;
		if (vec[left] > vec[max]) {
			max = left;
		}
	}

	if (right < size) {
		statistics.comparison_count++;
		if (vec[right] > vec[max]) {
			max = right;
		}
	}

	if (max != i) {
		custom_swap(vec[i], vec[max]);
		statistics.copy_count += 3;
		Heapify(vec, size, max, statistics);
	}
}

template <typename T>
Stats& HeapSort(std::vector<T>& vec) {
	Stats statistics;
	int size = vec.size();
	for (int i = size / 2 - 1; i >= 0; i--) {
		Heapify(vec, size, i, statistics);
	}

	for (int i = size - 1; i >= 0; i--) {
		custom_swap(vec[0], vec[i]);
		statistics.copy_count += 3;
		Heapify(vec, i, 0, statistics);
	}
	return statistics;
}

template <typename T>
vector<T> RandomVec(size_t size) {
	vector<T> vector(size);
	// Установка зерна для генератора случайных чисел
	std::mt19937 rng;
	rng.seed(std::time(0)); // Используем текущее системное время в качестве зерна

	// Генерация случайных чисел в заданном диапазоне
	std::uniform_int_distribution<int> distribution(0, 100000);

	// Генерация случайных чисел
	for (int i = 0; i < size; ++i) {
		vector[i] = distribution(rng);
	}
	return vector;
}

template <typename T>
vector<T> SortedVec(size_t size) {
	vector<T> vector(size);
	for (size_t i = 0; i < size; ++i) {
		vector[i] = i;
	}
	return vector;
}

template <typename T>
vector<T> ReverseSortedVec(size_t size) {
	vector<T> vector(size);
	for (size_t i = 0; i < size; ++i) {
		vector[i] = size - i;
	}
	return vector;
}
