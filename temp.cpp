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
int to[maxn], pre[maxn], last[maxn];
int cnt;

inline void addEdge (int u, int v)
{
    cnt ++;
    to[cnt] = v;
    pre[cnt] = last[u];
    last[u] = cnt;
}

int main()
{
    
    return 0;
}