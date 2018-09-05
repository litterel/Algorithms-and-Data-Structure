#ifndef INSERT_SORT
#define INSERT_SORT
#include<vector>
template <typename T>
void insert_sort(T a[], int n)
{
    if (n == 1)
        return;
    for (int i = 1; i < n; i++)
    {
        T now = a[i];
        int position = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            if (a[j] > now)
                a[j + 1] = a[j];
            else
            {
                position = j + 1;
                break;
            }
        }
        a[position] = now;
    }
}

template <typename T>
void insert_sort(std::vector<T> &a)
{
    int n = a.size();
    if (n == 1)
        return;
    for (int i = 1; i < n; i++)
    {
        T now = a[i];
        int position = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            if (a[j] > now)
                a[j + 1] = a[j];
            else
            {
                position = j + 1;
                break;
            }
        }
        a[position] = now;
    }
}

#endif