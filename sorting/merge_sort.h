#ifndef MERGE_SORT
#define MERGE_SORT
//#include <iostream>
#include <vector>

template <typename T>
void merge_array(std::vector<T> &a, int low, int mid, int high,
                 std::vector<T> &temp) {
    if (a[mid] <= a[mid + 1])
        return;

    while (low <= mid) {
        if (a[low] <= a[mid + 1])
            low++;
        else
            break;
    }
    while (high >= mid) {
        if (a[high] >= a[mid])
            high--;
        else
            break;
    }

    if (high - low <= 5) {
        int j = mid + 1;
        while (j <= high) {
            T now_value = a[j];
            int i = j - 1;
            // int posiition = low;
            while (i >= low) {
                if (a[i] > now_value) {
                    a[i + 1] = a[i];
                    i--;
                } else
                    break;
            }
            a[i + 1] = now_value;
            j++;
        }
        return;
    }

    int i = low;
    int k = 0;
    int j = mid + 1;

    // std::vector<T> *temp = new std::vector<T>;
    while (i <= mid && j <= high) {
        if (a[i] <= a[j]) {
            temp[k] = a[i];
            i++;
            k++;
        } else {
            temp[k] = a[j];
            j++;
            k++;
        }
    }
    while (j <= high) {
        temp[k] = a[j];
        j++;
        k++;
    }

    while (i <= mid) {
        temp[k] = a[i];
        i++;
        k++;
    }

    for (i = 0; i <= high - low; i++) {
        a[i + low] = temp[i];
    }
    // delete temp;
    return;
}

template <typename T>
void merge_sort(std::vector<T> &a, int low, int high, std::vector<T> &temp) {
    if (low >= high)
        return;
    int mid = (low + high) / 2;
    merge_sort(a, low, mid, temp);
    merge_sort(a, mid + 1, high, temp);
    merge_array(a, low, mid, high, temp);
}

template <typename T>
void merge_sort_r(std::vector<T> &a, std::vector<T> &temp) {
    //当n大于100000会报错，不知为何
    int n = a.size();
    int max_size = 2 * n;
    if (n == 1)
        return;
    int sub_size = 2;
    while (sub_size < max_size) {
        for (int start = 0; start <= n - 1; start += sub_size) {
            int low = start;
            int high = start + sub_size - 1;
            int mid = (low + high) / 2;

            if (high > n - 1) //这里需要格外小心
                high = n - 1;

            if (high != low)
                merge_array(a, low, mid, high, temp);
        }
        sub_size *= 2;
    }
}

#endif