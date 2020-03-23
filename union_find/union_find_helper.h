#ifndef UF_HELPER_H
#define UF_HELPER_H

#include "union_find.h"
#include <iostream>
#include <ctime>

namespace UF_helper
{
void test_UF(int n)
{
    union_find UF = union_find(n);
    srand(time(NULL));
    time_t start_time = clock();
    for (int i = 0; i < n; i++)
    {
        int inx_1 = rand() % n;
        int inx_2 = rand() % n;
        UF.union_elements(inx_1, inx_2);
    }
    for (int i = 0; i < n; i++)
    {
        int inx_1 = rand() % n;
        int inx_2 = rand() % n;
        UF.is_connected(inx_1, inx_2);
    }
    time_t end_time = clock();
    std::cout << "numbers of elements: " << n << std::endl;
    std::cout << double(end_time - start_time) / CLOCKS_PER_SEC << " s" << std::endl;
    return;
}
} // namespace UF_helper

#endif