#ifndef HEAP_SORT
#define HEAP_SORT
#include <vector>
#include "my_heap.h"

template <typename T>
void heap_sort(std::vector<T> &arr, int m = -1)
{
    int n = arr.size();
    //max_heap<T> my_heap(n);
    min_heap<T> my_heap(n);
    for (auto iter = arr.begin(); iter != arr.end(); iter++)
    {
        my_heap.insert(*iter);
    }

    int end = n;
    if (m > 0)
        end = std::min(n, m);
    for (int i = 0; i < end; i++)
    {
        arr[i] = my_heap.pop();
    }
}
template<typename T>
void heap_sort_inplace(T arr[],int n){
    
}
#endif