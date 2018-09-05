#ifndef BUBBLIE_SORT
#define BUBBLIE_SORT

#include<vector>
template <typename T>
void bubble_sort(std::vector<T> &a)
{
    auto n = a.size();
    if (n == 1)
        return;
    int step = 1;
    while (step < n)
    {
        for (int i = 0; i < n - step; i++)
        {
            if (a[i] > a[i + 1])
            {
                std::swap(a[i], a[i + 1]);
                //iter_swap(a.begin() + i, a.begin() + i + 1);
            }
        }
        step += 1;
    }
}

template <typename T>
void bubble_sort(T a[], int n)
{
    //int n = sizeof(a) / sizeof(a[0]);
    if (n == 1)
        return;
    int step = 1;
    while (step < n)
    {
        for (int i = 0; i < n - step; i++)
        {
            if (a[i] > a[i + 1])
            {
                std::swap(a[i], a[i + 1]);
            }
        }
        step += 1;
    }
}

#endif