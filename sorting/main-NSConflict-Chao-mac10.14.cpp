#include "my_heap.h"
#include "my_sort.h"
int main() {
    int n = 500000;
    auto xx = new int[n]; //尽量避免使用 int a[n]这种创建方式，会出现segmenta
                          // fault的报错。
    vector<int> x(n);
    vector<int> temp(n);

    for (int i = 0; i < n; i++) {
        x[i] = i;
    }

    cout << "length of array: " << n << endl;
    // int n = sizeof(a) / sizeof(a[0]);

    auto rng = default_random_engine{1};
    shuffle(x.begin(), x.end(), rng);

    cout << endl;
    for (int i = 0; i < n; i++) {
        xx[i] = x[i];
    }

    clock_t time1 = clock();

    // sort(x.begin(),x.end()); //stl内置排序算法，作为参照
    // select_sort(x);
    // select_sort2(x);
    // insert_sort(x);
    // quick_sort(x, 0, n - 1);
    // merge_sort(x, 0, n - 1,temp);
    // merge_sort_r(x, temp);
    // heap_sort(x,1000);

    // select_sort(xx, n);
    // select_sort2(xx, n); //使用数组要比vector速度快很多
    //quick_sort(xx,0,n-1);
    //qsort_nonrecur(xx,0,n-1);

    clock_t time2 = clock();

    auto intervals = (time2 - time1) * 1.0 / 1000;
    cout << "time needed for sorting: ";
    cout << intervals << " ms." << endl;

    /*
    max_heap<int> testheap(n+10);
    for (auto iter=x.begin();iter !=x.end();iter++){
        testheap.insert(*iter);
    }

    



    for (auto ele : x)
        cout << ele << ' ';
    cout<<endl;

    testheap.display();
    for(int i =0; i<10;i++){
        cout<<testheap.pop()<<endl;
        testheap.display();
    }
    */
    delete[] xx;
    return 0;
}