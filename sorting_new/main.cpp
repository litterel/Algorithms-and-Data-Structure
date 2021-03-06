#include "student.h"
#include "my_sort.h"
#include "sort_test_helper.h"

using namespace std;

int main()
{

    //template <typename T>
    //bool (*compare)(T, T) = my_less; //why this method fails.
    bool (*compare)(int, int) = my_less;
    int n = 100;
    int *arr = sort_test_helper::generat_random_array(n, 0, 100000);
    //int *arr = sort_test_helper::generate_nearly_ordered_array(n, 1000, compare);
    int *arr2 = sort_test_helper::copy_array(arr, n);
    int *arr3 = sort_test_helper::copy_array(arr, n);
    int *arr4 = sort_test_helper::copy_array(arr, n);
    /*
    sort_test_helper::print_array(arr, n);
    merge_bottom_up(arr, n, compare);
    cout << sort_test_helper::is_sorted(arr, n, compare) << endl;
    sort_test_helper::print_array(arr, n);
    */

    cout << "size of array: " << n << endl;
    sort_test_helper::test_sort(arr, n, "merge_sort", merge_sort, compare);
    //sort_test_helper::test_sort(arr2, n, "insert_sort", insert_sort, compare);
    //sort_test_helper::test_sort(arr3, n, "merge_sort_2", merge_bottom_up, compare);
    sort_test_helper::test_sort(arr2, n, "heap_sort", my_heap_sort, compare);
    sort_test_helper::test_sort(arr3, n, "heap_sort_inplace", heap_sort_inplace, compare);

    sort_test_helper::test_sort(arr4, n, "quick_sort", quick_sort, compare);
    /*
    student d[5] = {{"D", 90}, {"C", 100}, {"A", 85}, {"B", 80}, {"E", 80}};
    select_sort(d, 5, my_less);
    for (int i = 0; i < 5; i++)
        cout << d[i];
    */
    int ans = 0;
    int max_number = 100;
    for (int i = max_number / 4 ; i <= max_number; i++)
        for (int j = (max_number - i) / 3 ; j <= min(max_number - i, i); j++)
            for (int k = (max_number - i - j) / 2 ; k <= min(max_number - i - j, j); k++)
                for (int z = 1; z <= min(max_number - i - j - k, k); z++)
                {
                    if (i + j + k + z == 100)
                        ans++;
                }

    cout << ans << endl;
    delete[] arr;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    return 0;
}