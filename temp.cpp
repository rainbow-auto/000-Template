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

const int maxn = 1000010;
int n;

int h[maxn];
int ph[maxn]; // 第k个插入到点的位置
int hp[maxn]; // 第i个点是第几个插入的
int siz;

inline void heap_swap (int a, int b)
{
    swap (h[a], h[b]);
    swap (hp[a], hp[b]);
    swap (ph[hp[a]], ph[hp[b]]);
}

void up (int x)
{
    if (x / 2 > 0 and h[x] < h[x / 2])
    {
        heap_swap (x, x / 2);
        up (x / 2);
    }
}

void down (int x)
{
    int t = x;
    if (x * 2 <= siz and h[t] > h[x * 2]) t = x * 2;
    
    if (x * 2 + 1 <= siz and h[t] > h[x * 2 + 1]) t = x * 2 + 1;

    if (t != x)
    {
        heap_swap (x, t);
        down (t);
    }
}

int main()
{

    return 0;
}