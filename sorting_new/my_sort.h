#ifndef MY_SORT_H
#define MY_SORT_H
using namespace std;

template <typename T>
bool my_less(T a, T b)
{
    return a < b;
}
template <typename T>
bool my_less_equal(T a, T b)
{
    return a < b || a == b;
}
template <typename T>
bool my_greater(T a, T b)
{
    return a > b;
}
template <typename T>
void select_sort(T arr[], int n, bool (*compare)(T, T) = my_less)
{
    for (int i = 0; i < n - 1; i++)
    {
        int inx = i;
        for (int j = i + 1; j < n; j++)
        {
            //if (arr[j] < arr[inx])
            if (compare(arr[j], arr[inx]))
            {
                inx = j;
            }
        }
        std::swap(arr[i], arr[inx]);
    }
    return;
}
template <typename T>
void insert_sort(T arr[], int n, bool (*compare)(T, T) = my_less)
{
    if (n == 1)
        return;
    for (int i = 1; i < n; i++)
    {
        int inx = i;
        int pivot = arr[i];
        for (int j = i - 1; j >= 0; j--)
        {
            if (!compare(pivot, arr[j]))
                break;
            arr[j + 1] = arr[j];
            inx = j;
        }
        arr[inx] = pivot;
    }
    return;
}
template <typename T>
void bubble_sort(T arr[], int n, bool (*compare)(T, T) = my_less)
{
    if (n == 1)
        return;

    return;
}
template <typename T>
void __merge_array(T arr[], T assist[], int left, int mid, int right, bool (*compare)(T, T))
{
    int inx = left;
    int i = left, j = mid + 1;
    while (i <= mid && j <= right)
    {
        if (compare(arr[i], arr[j]) || arr[i] == arr[j])
        {
            assist[inx] = arr[i];
            i++;
            inx++;
        }
        else
        {
            assist[inx] = arr[j];
            j++;
            inx++;
        }
    }
    while (i <= mid)
    {
        assist[inx] = arr[i];
        i++;
        inx++;
    }
    while (j <= right)
    {
        assist[inx] = arr[j];
        j++;
        inx++;
    }
    for (int i = left; i <= right; i++)
        arr[i] = assist[i];
    return;
}
template <typename T>
void __merge_sort(T arr[], T assist[], int left, int right, bool (*compare)(T, T))
{
    if (right - left <= 15)
    {
        insert_sort(arr + left, right - left + 1, compare);
        return;
    }
    if (left >= right)
        return;
    int mid = left + (right - left) / 2;
    __merge_sort(arr, assist, left, mid, compare);
    __merge_sort(arr, assist, mid + 1, right, compare);
    if (compare(arr[mid], arr[mid + 1]) || arr[mid] == arr[mid + 1])
        return;
    __merge_array(arr, assist, left, mid, right, compare);
    return;
}

template <typename T>
void merge_sort(T arr[], int n, bool (*compare)(T, T))
{
    T *assist = new T[n];
    __merge_sort(arr, assist, 0, n - 1, compare);
    delete[] assist;
}
template <typename T>
void merge_bottom_up(T arr[], int n, bool (*compare)(T, T))
{
    int sz = 15; // To enhance performances, batch-order the array with insert sort before iteration.
    for (int i = 0; i < n; i += sz)
        insert_sort(arr + i, min(sz, n), compare);
    T *assist = new T[n];
    while (sz <= n)
    {
        for (int i = 0; i + sz < n; i += (sz * 2))
            __merge_array(arr, assist, i, i + sz - 1, min(n - 1, i + 2 * sz - 1), compare);
        sz += sz;
    }
    delete[] assist;
    return;
}
template <typename T>
int __partition_array(T arr[], int left, int right, bool (*compare)(T, T))
{

    srand(time(NULL)); // Randomly choose an element as pivot, enhancing performances in case of a nearly ordered array
    int rand_inx = rand() % (right - left + 1);
    swap(arr[left], arr[left + rand_inx]);

    T pivot = arr[left];
    int i = left;
    int j = right;

    while (i < j)
    {
        while ((compare(pivot, arr[j]) || arr[j] == pivot) && i < j)
            j--;
        while ((compare(arr[i], pivot) || arr[i] == pivot) && i < j)
            i++;
        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[left], arr[i]);

    int mid = left + (right - left) / 2;
    while (i < mid && arr[i + 1] == arr[i])
        i++;
    while (i > mid && arr[i - 1] == arr[i])
        i--;

    return i;
}

template <typename T>
void __quick_sort(T arr[], int left, int right, bool (*compare)(T, T))
{
    if (left >= right)
        return;
    if (right - left < 15)
    {
        insert_sort(arr + left, right - left + 1, compare);
        return;
    }

    int mid = __partition_array(arr, left, right, compare);
    __quick_sort(arr, left, mid - 1, compare);
    __quick_sort(arr, mid + 1, right, compare);
    return;
}

template <typename T>
void quick_sort(T arr[], int n, bool (*compare)(T, T))
{
    if (n == 1)
        return;
    __quick_sort(arr, 0, n - 1, compare);
    return;
}
#endif