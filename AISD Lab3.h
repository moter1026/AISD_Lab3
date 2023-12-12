#pragma once

#include <iostream>
#include <vector>

class Stats {
public:
    size_t comparison_count = 0;
    size_t copy_count = 0;
};



template <typename T>
Stats& InsertSort(std::vector<T>& vec) {
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

template<typename T>
void custom_swap(T& obj1, T& obj2) {
    T copy = obj1;
    obj1 = obj2;
    obj2 = copy;
}

//template <typename T>
//Stats& ShakerSort(std::vector<T>& vec) {
//    Stats statistics;
//    size_t n = vec.size();
//    bool swapped;
//    do {
//        swapped = false;
//        for (size_t i = 0; i < n - 1; ++i) {
//            statistics.comparison_count++;
//            if (vec[i] > vec[i + 1]) {
//                custom_swap(vec[i], vec[i + 1]);
//                statistics.copy_count += 3;
//                swapped = true;
//            }
//        }
//        if (!swapped) break;
//
//        swapped = false;
//        for (size_t i = n - 1; i > 0; --i) {
//            statistics.comparison_count++;
//            if (vec[i - 1] > vec[i]) {
//                custom_swap(vec[i - 1], vec[i]);
//                statistics.copy_count += 3;
//                swapped = true;
//            }
//        }
//    } while (swapped);
//
//    return statistics;
//}

template <typename T>
Stats& ShakerSortMy(std::vector<T>& vec) {
    Stats statistics;
    size_t n = vec.size();
    while (n > 0) {
        for (size_t i = 0; i < n - 1; ++i) {
            statistics.comparison_count++;
            if (vec[i] > vec[i + 1]) {
                custom_swap(vec[i], vec[i + 1]);
                statistics.copy_count += 3;
            }
        }
        n--;
        if (n <= 0) break;
        for (size_t i = n - 1; i > 0; --i) {
            statistics.comparison_count++;
            if (vec[i - 1] > vec[i]) {
                custom_swap(vec[i - 1], vec[i]);
                statistics.copy_count += 3;
            }
        }
        n--;
    }
    return statistics;
}