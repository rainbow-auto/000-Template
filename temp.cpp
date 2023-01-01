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

const int maxn = 100005;
int n, m;
int a[maxn];
int sub[maxn]; // 差分
int sum[maxn]; // 前缀和

inline void insert (int l, int r, int x)
{
    sub[l] += x;
    sub[r + 1] -= x;
}

inline void init ()
{
    for (int i = 1; i <= n; i++)
    {
        insert(i, i, a[i]);
    }
}

inline void build_sum ()
{
    for (int i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + sub[i];
    }
}

int main()
{
    n = Reader::read(), m = Reader::read();
    
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    init();

    for (int i = 1; i <= m; i++)
    {
        int l, r, x;
        cin >> l >> r >> x;
        insert (l, r, x);
    }

    build_sum();
    for (int i = 1; i <= n; i++)
    {
        cout << sum[i] << " ";
    }

    return 0;
}