#ifndef MYSORT_TEST_H
#define MYSORT_TEST_H

#include <algorithm> // std::random_shuffle
#include <cstdlib>   // std::rand, std::srand
#include <ctime>     // std::time
#include <iostream>
#include <random>
#include <string>
#include <vector>

#include "heap_sort.h"
#include "insert_sort.h"
#include "merge_sort.h"
#include "my_heap.h"
#include "quick_sort.h"
#include "select_sort.h"
#include "shell_sort.h"

using std::cout;
using std::default_random_engine;
using std::endl;
using std::string;
using std::swap;
using std::uniform_int_distribution;

namespace my_sort {

template <typename T> void generate_random_permutation(T arr[], int n) {
    // auto xx = new int[n];
    auto rng = default_random_engine{1};
    for (int i = 0; i < n; i++) {
        auto inx = uniform_int_distribution<>(i, n - 1);
        swap(arr[i], arr[inx(rng)]);
    }
}

template <typename T> void generate_quasi_sorted_array(T arr[], int n) {
    auto rng = default_random_engine{1};
    auto inx = uniform_int_distribution<>(0, n - 1);
    for (int i = 0; i < n / 20; i++) {
        swap(arr[inx(rng)], arr[inx(rng)]);
    }
}

template <typename T> void display(T arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template <typename T>
void test_sort(string sort_name, void (*sort_func)(T[], int), T arr[], int n) {
    cout << "length of the array: " << n << endl;
    cout << sort_name << endl;

    clock_t time1 = clock();
    sort_func(arr, n);
    clock_t time2 = clock();

    auto intervals = (time2 - time1) * 1.0 / 1000;
    cout << "time needed for sorting: " << intervals << " ms." << endl;
}

} // namespace my_sort
#endif
