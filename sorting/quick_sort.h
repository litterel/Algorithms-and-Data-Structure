#ifndef QUICK_SORT
#define QUICK_SORT

#include <stack>
#include <vector>
template <typename T> void quick_sort(std::vector<T> &a, int low, int high) {
    if (low >= high)
        return; //退出递归的标志是左右下标重合，此时排序结束

    T pivot_value = a[low];
    int i = low;
    int j = high;
    while (i < j) {
        while (a[j] >= pivot_value && i < j)
            j -= 1;
        while (a[i] <= pivot_value && i < j)
            i += 1;

        std::swap(a[i], a[j]);
    }
    std::swap(a[low], a[i]);

    quick_sort(a, low, i - 1);
    quick_sort(a, i + 1, high);
}

template <typename T> void quick_sort(T a[], int low, int high) {
    if (low >= high)
        return; //退出递归的标志是左右下标重合，此时排序结束

    T pivot_value = a[low];
    int i = low;
    int j = high;
    while (i < j) {
        while (a[j] >= pivot_value && i < j)
            j -= 1;
        while (a[i] <= pivot_value && i < j)
            i += 1;

        std::swap(a[i], a[j]);
    }
    std::swap(a[low], a[i]);

    quick_sort(a, low, i - 1);
    quick_sort(a, i + 1, high);
}

template <typename T>
void qsort_nonrecur(std::vector<T> &a, int low, int high) {
    std::stack<std::pair<int, int>> inx;
    inx.push(std::pair<int, int>{low, high});
    while (!inx.empty()) {
        auto parameters = inx.top(); //读取栈顶元素作为下一次分割的数组下标
        inx.pop();

        //分割数组
        low = parameters.first;
        high = parameters.second;
        if (low < high) {
            T pivot_value = a[low];
            int i = low;
            int j = high;
            while (i < j) {
                while (a[j] >= pivot_value && i < j)
                    j -= 1;
                while (a[i] <= pivot_value && i < j)
                    i += 1;
                std::swap(a[i], a[j]);
            }
            std::swap(a[low], a[i]);

            //将分割之后的子数组下标压入栈
            inx.push(std::pair<int, int>{low, i - 1});
            inx.push(std::pair<int, int>{i + 1, high});
        }
    }
}

template <typename T> void qsort_nonrecur(T a[], int low, int high) {
    std::stack<std::pair<int, int>> inx;
    inx.push(std::pair<int, int>{low, high});
    while (!inx.empty()) {
        auto parameters = inx.top(); //读取栈顶元素作为下一次分割的数组下标
        inx.pop();

        //分割数组
        low = parameters.first;
        high = parameters.second;
        if (low < high) {
            T pivot_value = a[low];
            int i = low;
            int j = high;
            while (i < j) {
                while (a[j] >= pivot_value && i < j)
                    j -= 1;
                while (a[i] <= pivot_value && i < j)
                    i += 1;
                std::swap(a[i], a[j]);
            }
            std::swap(a[low], a[i]);

            //将分割之后的子数组下标压入栈
            inx.push(std::pair<int, int>{low, i - 1});
            inx.push(std::pair<int, int>{i + 1, high});
        }
    }
}

template <typename T> T quick_find(T a[], int l, int r, int m) {

    int i = l;
    int j = r;
    T pivot = a[l];
    while (i < j) {
        while (a[j] >= pivot && i < j)
            j--;
        while (a[i] <= pivot && i < j)
            i++;
        std::swap(a[i], a[j]);
    }
    std::swap(a[i], a[l]);
    if (i == m) {
        return a[i];
    } else if (m < i)
        return quick_find(a, l, i - 1, m);
    else
        return quick_find(a, l + 1, r, m);
}

template <typename T> T find_mth(T a[], int n, int m) {
    m = m - 1;
    return quick_find(a, 0, n - 1, m);
}

#endif