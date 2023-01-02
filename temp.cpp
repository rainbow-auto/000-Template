#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

namespace Reader
{
    int read()
    {
        char c = getchar();
        int x = 0, flag = 1;
        while (not isdigit(c))
        {
            if (c == '-')
                flag = -1;
            c = getchar();
        }
        while (isdigit(c))
        {
            x = x * 10 + c - '0';
            c = getchar();
        }
        return x * flag;
    }
}

vector<int> all; // 所有需要离散化的数

inline void discretize ()
{
    sort (all.begin(), all.end());
    all.erase (unique (all.begin(), all.end()), all.end());
}

inline int find (int x) // 原来值为x, 对应值为find(x)
{
    int l = 0, r = all.size() - 1;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (all[mid] >= x) r = mid;
        else l = mid - 1;
    }
    return l + 1; // 下标从1开始则 + 1
}

int main()
{

    return 0;
}