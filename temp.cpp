#include <iostream>
#include <algorithm>
#include <queue>
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
int w[maxn];

inline void addEdge (int u, int v, int ww)
{
    cnt ++;
    to[cnt] = v;
    w[cnt] = ww;
    pre[cnt] = last[u];
    last[u] = cnt;
}

struct Node{
    int id;
    int dis;
    friend bool operator < (Node a, Node b)
    {
        return a.dis > b.dis; // priority_queue
    }
};

bool vis[maxn];
int dis[maxn];
bool dij (int s)
{
    memset (dis, 0x3f, sizeof (dis));
    dis[s] = 0;
    priority_queue <Node> q;
    q.push (Node{s, dis[s]});

    while (not q.empty ())
    {
        int u = q.top().id; q.pop();
        if (vis[u]) continue;
        vis[u] = true;

        for (int i = last[u]; i ; i = pre[i])
        {
            int v = to[i];
            if (dis[v] > dis[u] + w[i])
            {
                dis[v] = dis[u] + w[i];
                q.push (Node{v, dis[v]});
            }
        }
    }
    
    if (dis[n] == 0x3f3f3f3f) return false;
    else return true;
}

int main()
{
    n = Reader::read();
    m = Reader::read();

    for (int i = 1; i <= m; i++)
    {
        int u = Reader::read();
        int v = Reader::read();
        int ww = Reader::read();
        addEdge (u, v, ww);        
    }

    if (dij (1))
    {
        cout << dis[n] << endl;
    }
    else
    {
        cout << "-1" << endl;
    }

    return 0;
}