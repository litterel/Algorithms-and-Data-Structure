#ifndef UNION_FIND_H
#define UNION_FIND_H

#include <iostream>
#include <cassert>
//using namespace std;

class union_find
{
private:
    int *parents;
    int *rank;
    int count;

public:
    union_find(int n)
    {
        count = n;
        parents = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; i++)
        {
            parents[i] = i;
            rank[i] = 1;
        }
    }
    ~union_find()
    {
        delete[] parents;
        delete[] rank;
    }
    int find_parent(int inx)
    {
        if (parents[inx] != inx)
            parents[inx] = find_parent(parents[inx]); //path compressing
        return parents[inx];
    }
    bool is_connected(int p, int q)
    {
        return find_parent(p) == find_parent(q);
    }

    void union_elements(int p, int q)
    {
        int p_parent = find_parent(p);
        int q_parent = find_parent(q);
        parents[p] = parents[q];
        return;
    }
};

#endif