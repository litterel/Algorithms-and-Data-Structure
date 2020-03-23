#ifndef HEAP_SORT_H
#define HEAP_SORT_H
#include <iostream>
template <typename T>

class max_heap
{
private:
    T *heap = NULL;
    int capacity;
    int count = 0;

    void shift_up(int n)
    {
        T temp = heap[n];
        while (n > 1 && heap[n / 2] < temp)
        {
            heap[n] = heap[n / 2];
            n = n / 2;
        }
        heap[n] = temp;
        return;
    }
    void shift_down(int n)
    {
        T temp = heap[n];
        while (2 * n <= count)
        {

            int max_inx = 2 * n;
            if (max_inx + 1 <= count && heap[max_inx + 1] > heap[max_inx])
                max_inx = 2 * n + 1;
            if (heap[max_inx] <= temp)
                break;
            heap[n] = heap[max_inx];
            //std::swap(heap[max_inx], heap[n]);
            n = max_inx;
        }
        heap[n] = temp;
        return;
    }
    void heapify()
    {
        for (int i = count / 2; i >= 1; i--)
            shift_down(i);
        return;
    }

public:
    max_heap(int n)
    {
        capacity = n;
        heap = new T[capacity + 1];
        int count = 0;
    }
    max_heap(T *arr, int n)
    {
        capacity = n;
        heap = new T[capacity + 1];
        count = n;
        for (int i = 0; i < n; i++)
            heap[i + 1] = arr[i];
        heapify();
    }
    ~max_heap()
    {
        delete[] heap;
    }
    int size()
    {
        return count;
    }
    void insert(T item)
    {
        if (count >= capacity)
        {
            std::cout << "Out of capacity." << std::endl;
            return;
        }
        count += 1;
        heap[count] = item;
        shift_up(count);
    }

    T pop_max()
    {
        if (count == 0)
        {
            std::cout << "Empty heap!" << std::endl;
            return NULL;
        }
        T ret = heap[1];
        std::swap(heap[1], heap[count]);
        count--;
        shift_down(1);
        return ret;
    }
};

template <typename T>
void my_heap_sort(T arr[], int n, bool (*comapre)(T, T))
{
    max_heap<T> my_heap = max_heap<T>(arr, n);
    for (int i = 0; i < n; i++)
    {
        arr[n - 1 - i] = my_heap.pop_max();
    }
    return;
}
#endif
