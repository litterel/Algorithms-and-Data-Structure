#include "my_heap.h"
#include "my_sort.h"
using namespace std;

int main() {
    int n = 200;
    int *xx = new int[n]; //尽量避免使用 int a[n]这种创建方式，会出现segmenta
                          // fault的报错。
    for (int i = 0; i < n; i++) {
        xx[i] = i;
    }
    my_sort::generate_random_permutation(xx, n);
    // my_sort::generate_quasi_sorted_array(xx, n);
    // my_sort::display(xx, n);

    vector<int> x(n);
    vector<int> temp(n);

    for (int i = 0; i < n; i++) {
        x[i] = xx[i];
    }
    cout << endl;

    time_t time1 = clock();
    // sort(x.begin(),x.end()); //stl内置排序算法，作为参照
    // select_sort(x);
    // select_sort2(x);
    // insert_sort(x);
    // quick_sort(x, 0, n - 1);
    // merge_sort(x, 0, n - 1,temp);
    // merge_sort_r(x, temp);

    // heap_sort(x, 100);
    // select_sort(xx, n);
    // select_sort2(xx, n); //使用数组要比vector速度快很多
    // quick_sort(xx, 0, n - 1);
    // qsort_nonrecur(xx,0,n-1);

    time_t time2 = clock();
    auto intervals = double(time2 - time1)  / CLOCKS_PER_SEC;
    cout << "time needed for sorting: " << intervals << " s." << endl;

    max_heap<int> myheap(xx, n);
    myheap.display();
    for (int i = 0; i < n; i++) {
        cout << myheap.pop() << " ";
    }
    cout << endl;
    cout << myheap.get_size() << endl;

    cout<<find_mth(xx, n, 40) << endl;

    delete[] xx;
    xx = nullptr;
    return 0;
}