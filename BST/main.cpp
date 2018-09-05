#include "bst.h"
#include <iostream>
#include <random>
#include <string>
#include <vector>
using namespace std;

class test_class {
  private:
    int m;

  public:
    test_class() { m = 1; }
    int *get_item() { return &m; }
    void display() { cout << m << endl; }
};

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
    auto rng = default_random_engine{1};
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

    int n = 100;
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

    BST<int, int> my_tree;
    for (int i = 0; i < n; i++) {
        my_tree.insert_r(arr[i], 0);
    }
    test_array::display_array(arr, n);
    // my_tree.pre_order();

    cout << "size: " << my_tree.get_size() << endl;
    // cout << "if null: " << my_tree.is_null() << endl;

    cout << my_tree.contain(6) << endl;
    cout << "pre order: " << endl;
    my_tree.pre_order();
    cout << endl;

    cout << "in order: " << endl;
    my_tree.mid_order();
    cout << endl;

    cout << "post order: " << endl;
    my_tree.post_order();
    cout << endl;

    cout << "layer order: " << endl;
    my_tree.layer_order();
    cout << endl;
    return 0;
}