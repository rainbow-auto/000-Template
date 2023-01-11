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
int n, m;

int to[maxn], pre[maxn], last[maxn];
int cnt;

inline void addEdge (int u, int v)
{
    cnt ++;
    to[cnt] = v;
    pre[cnt] = last[u];
    last[u] = cnt;

    ind[v] ++;
}

int ind[maxn];
vector<int> topsort ()
{
    vector<int> ans;
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (ind[i] == 0)
        {
            q.push(i);
        }
    }

    while (not q.empty())
    {
        int u = q.front(); q.pop();
        ans.push_back(u);
        for (int i = last[u]; i; i = pre[i])
        {
            int v = to[i];
            in[v]--;
            if (in[v] == 0)
            {
                q.push(v);
            }
        }
    }

    if (ans.size() == n)
    {
        return ans;
    }
    else
    {
        return vector(1, -1);
    }
}

int main()
{
    n = Reader::read();
    m = Reader::read();

    for (int i = 1; i <= m; i++)
    {
        int u = Reader::read();
        int v = Reader::read();

        addEdge (u, v);        
    }

    vector<int> ans = topsort();

    if (ans.front() == -1)
    {

    }
    else
    {
    
    }

    return 0;
}