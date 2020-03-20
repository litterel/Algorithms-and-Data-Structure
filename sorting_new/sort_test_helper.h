#ifndef SORT_TEST_HELP
#define SORT_TEST_HELP

#include <iostream>
#include <ctime>
#include <cassert>

using namespace std;

namespace sort_test_helper
{

int *generat_random_array(int n, int rangeL, int rangeR)
{
    assert(rangeL <= rangeR);
    int *arr = new int[n];
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
    return arr;
}
template <typename T>
T *generate_nearly_ordered_array(int n, int swaps, bool (*compare)(T, T))
{
    int *arr = new T[n];
    if (compare(int(0), int(1)))
    {
        for (int i = 0; i < n; i++)
            arr[i] = i;
    }
    else
    {
        for (int i = 0; i < n; i++)
            arr[i] = n - i - 1;
    }
    srand(time(NULL));
    for (int i = 0; i < swaps; i++)
    {

        int px = rand() % n;
        int py = rand() % n;
        swap(arr[px], arr[py]);
    }
    return arr;
}

template <typename T>
void print_array(T arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return;
}

template <typename T>
T *copy_array(T arr[], int n)
{
    T *arr2 = new T[n];
    copy(arr, arr + n, arr2);
    return arr2;
}

template <typename T>
bool is_sorted(T arr[], int n, bool (*compare)(T, T))
{
    if (n == 1)
        return true;
    for (int i = 0; i < n - 1; i++)
    {
        if (!compare(arr[i], arr[i + 1]) && !(arr[i] == arr[i + 1]))
            return false;
    }
    return true;
}

template <typename T>
void test_sort(T arr[], int n, string sort_name, void (*sort)(T[], int, bool (*compare)(T, T)), bool (*compare)(T, T))
{
    clock_t start_time = clock();
    sort(arr, n, compare);
    clock_t end_time = clock();
    assert(is_sorted(arr, n, compare));
    cout << sort_name << ": " << double(end_time - start_time) / CLOCKS_PER_SEC << " s" << endl;
}
} // namespace sort_test_helper

#endif