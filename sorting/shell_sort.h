#ifndef SHELL_SORT
#define SHELL_SORT
#include <vector>

template <typename T> void shell_sort(std::vector<T> &a) {
    int n = a.size();
    if (n == 1)
        return;

    int d = int(sqrt(n));
    while (d >= 1) {
        //数组被分割为 d 组，组内元素间隔为 d，对每个子数组进行插入排序
        for (int start = 0; start < d; start++) {
            for (int i = start + d; i < n; i += d) {
                int now = a[i];
                int position = start;
                for (int j = i - d; j >= start; j -= d) {
                    if (a[j] > now)
                        a[j + d] = a[j];
                    else {
                        position = j + d;
                        break;
                    }
                }
                a[position] = now;
            }
        }
        d = d / 2;
    }
}

#endif