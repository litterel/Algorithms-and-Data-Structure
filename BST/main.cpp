//#include "bst.h"

#include "bst_new.h"
#include <ctime>
#include <iostream>
#include <random>
#include <string>
#include <vector>
using namespace std;

namespace test_array {
template <typename T> void generate_random_permutation(T arr[], int n) {
    // auto xx = new int[n];
    auto rng = default_random_engine{1};
    for (int i = 0; i < n; i++) {
        auto inx = uniform_int_distribution<>(i, n - 1);
        swap(arr[i], arr[inx(rng)]);
    }
}

template <typename T> void generate_quasi_sorted_array(T arr[], int n) {
    auto rng = default_random_engine{2};
    auto inx = uniform_int_distribution<>(0, n - 1);
    for (int i = 0; i < n / 20; i++) {
        swap(arr[inx(rng)], arr[inx(rng)]);
    }
}

template <typename T> void display_array(T arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
}; // namespace test_array

int main() {

    int n = 10;
    int *values = new int[n];
    int *arr = new int[n]; //尽量避免使用 int a[n]这种创建方式，会出现segmenta
                           // fault的报错。

    for (int i = 0; i < n; i++) {
        arr[i] = i;
        values[i] = 0;
    }

    test_array::generate_random_permutation(arr, n);
    // test_array::display_array(arr, n);
    cout << endl;
    time_t time1 = clock();
    bst<int, int> my_tree;
    for (int i = 0; i < n; i++) {
        my_tree.insert(arr[i], 0);
    }
    time_t time2 = clock();
    auto intervals = double(time2 - time1) / CLOCKS_PER_SEC;
    cout << "time needed for constructing tree: " << intervals << " s." << endl;

    // cout << "Original array: " << endl;
    // test_array::display_array(arr, n);
    // my_tree.pre_order();
    //my_tree.remove_min();
    //my_tree.remove_max();
    my_tree.remove(2);
    cout << "size: " << my_tree.get_size() << endl;

    cout << "rank is: " << my_tree.rank(6) << endl;
    cout << "select element: " << my_tree.select(3) << endl;
    cout << "pre order: " << endl;
    my_tree.pre_order();
    cout << endl;

    cout << "in order: " << endl;
    my_tree.in_order();
    cout << endl;

    cout << "post order: " << endl;
    my_tree.post_order();
    cout << endl;

    cout << "layer order: " << endl;
    my_tree.layer_order();
    cout << endl;

    cout << my_tree.min() << "\t" << my_tree.max() << endl;

    return 0;
}