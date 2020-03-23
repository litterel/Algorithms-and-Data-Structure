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
        while (n > 1 && heap[n / 2] < heap[n])
        {
            std::swap(heap[n / 2], heap[n]);
            n = n / 2;
        }
    }
    void shift_down(int n)
    {
        while (2 * n <= count)
        {
            int max_inx = 2 * n;
            if (max_inx + 1 <= count && heap[max_inx + 1] > heap[max_inx])
                max_inx = 2 * n + 1;
            if (heap[max_inx] <= heap[n])
                break;
            std::swap(heap[max_inx], heap[n]);
            n = max_inx;
        }
        return;
    }

public:
    max_heap(int n)
    {
        capacity = n;
        heap = new T[capacity + 1];
        int count = 0;
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

#endif