#ifndef SELECT_SORT
#define SELECT_SORT
#include <vector>

template <typename T> void select_sort(std::vector<T> &a) {
    int n = a.size();
    if (n == 1)
        return;
    for (int i = 0; i < n - 1; i++) {
        int min_inx = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min_inx])
                min_inx = j;
        }
        std::swap(a[i], a[min_inx]);
    }
}

template <typename T> void select_sort(T a[], int n) {
    if (n == 1)
        return;
    for (int i = 0; i < n - 1; i++) {
        int min_inx = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min_inx])
                min_inx = j;
        }
        std::swap(a[i], a[min_inx]);
    }
}

template <typename T> void select_sort2(std::vector<T> &a) {
    //每次将最小值放在首位，最大值放在末位
    int n = a.size();
    if (n == 1)
        return;
    int i = 0;
    int k = n - 1;
    while (i < k) {
        int min, max = i;
        for (int j = i; j <= k; j++) {
            if (a[j] < a[min])
                min = j;
            if (a[j] > a[max])
                max = j;
        }
        if (min != i)
            std::swap(a[min], a[i]);
        if (max == i)
            std::swap(a[k], a[min]);
        else
            std::swap(a[max], a[k]);
        i++;
        k--;
    }
}

template <typename T> void select_sort2(T a[], int n) {
    //每次将最小值放在首位，最大值放在末位
    if (n == 1)
        return;
    int i = 0;
    int k = n - 1;
    while (i < k) {
        int min, max = i;
        for (int j = i; j <= k; j++) {
            if (a[j] < a[min])
                min = j;
            if (a[j] > a[max])
                max = j;
        }
        if (min != i)
            std::swap(a[min], a[i]);
        if (max == i)
            std::swap(a[k], a[min]);
        else
            std::swap(a[max], a[k]);
        i++;
        k--;
    }
}

#endif