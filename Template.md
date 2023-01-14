# OI-TEMPLATE

Powered by caotianlang@outlook.com

## 火车头

```cpp
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <queue> 
#include <algorithm>

#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
using namespace std;

typedef long long ll;
#define Debug cout

inline int read ()
{
    int res = 0, flag = 1;
    char ch = getchar ();
    while (not isdigit(ch)) 
    {
        if (ch == '-') flag = -1;
        ch = getchar ();
    }
    while (isdigit(ch))
    {
        res = res * 10 + int (ch - '0');
        ch = getchar ();
    }
    return res * flag;
}

int main ()
{

    return;
}
```

## 数学

### 快速幂

```cpp
ll ksm (ll a, ll b, ll p)
{
    ll res = 1;
    for (ll base = a; b; b >>= 1, base *= base, base %= p) 
        if (b & 1) res *= base, res %= p;
    return res;
}
```

### gcd / lcm

```cpp
ll gcd (ll a, ll b)
{
    return b ? gcd (b, a % b) : a;
}

ll lcm (ll a, ll b)
{
    return a * b / gcd (a, b);
}
```

## 数据结构

### 区间RMQ

#### 前缀和

##### 一维

```cpp
inline void init ()
{
    for (int i = 1; i <= n; i++)
        s[i] = a[i] + s[i - 1];
}

inline int sum (int l, int r)
{
    return s[r] - s[l - 1];
}
```

##### 二维

```cpp
inline void init ()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
}

inline int sum (int x1, int y1, int x2, int y2)
{
    return s[x2][y2] - s[x1][y2] - s[x2][y1] + s[x1][y2];
}
```

#### 树状数组

```cpp
const int maxn = 10005;
int n;
int a[maxn];
int s[maxn];
int tr[maxn];

inline int lowbit (int x) {return x & (-x);}

inline void build ()
{
    for (int i = 1; i <= n; i++)
    {
        s[i] = s[i - 1] + a[i];
        tr[i] = s[i] - s[i - lowbit(i)];
    }
}

inline int add (int pos, int x)
{
    for (int i = pos; i <= n; i += lowbit (i)) tr[i] += x;
}

inline void sum (int pos)
{
    int res = 0;
    for (int i = 1; i <= pos; i += lowbit(i)) res += tr[i];
    return res;
}
```

#### 线段树

```cpp
// 
```

#### 分块

### 并查集

```cpp
int n;
int fa[maxn];

inline void init ()
{
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
    }    
}

int find (int x)
{
    if (fa[x] != x)
    {
        return fa[x] = find (fa[x]);
    }
    return fa[x];
}
```

## 图论

### 前向星

```cpp
int to[maxn], pre[maxn], last[maxn];
int w[maxn];
int cnt;

inline void addEdge (int u, int v, int ww)
{
    cnt ++;
    to[cnt] = v;
    pre[cnt] = last[u];
    w[cnt] = ww;
    last[u] = cnt;
}
```

### 最短路

#### Dijkstra

```cpp
struct Node{
    int id;
    int dis;
    friend bool operator < (Node a, Node b)
    {
        return a.dis > b.dis;
    }
};

int dis[maxn];
bool vis[maxn];
void dij (int s)
{
    priority_queue <Node> q;
    memset (vis, 0, sizeof (vis));
    memest (dis, 0x3f, sizeo (dis));
    dis[s] = 0;
    q.push (Node{s, dis[s]});
    while (not q.empty ())
    {
        int u = q.top().id; q.pop ();
        if (vis[u]) continue;
        vis[u] = true;
        for (itnt i = last[u]; i; i = pre[i])
        {
            int v = to[i];
            if (dis[v] > dis[u] + w[i])
            {
                dis[v] = dis[u] + w[i];
                q.push (Node{v, dis[v]});
            }
        }
    }
    return;
}
```

#### SPFA (判断负环).

```cpp
int dis[maxn];
int times[maxn]; //次数
bool inq[maxn];

queue <int> q;

bool spfa (int s)
{
    memset (dis, 0, sizeof (dis));
    memset (inq, 0, sizeof (inq));
    q.push (s);
    dis[s] = 0;

    while (not q.empty ())
    {
        int u = q.front (); q.pop ();
        inq[u] = false;
        for (int i = last[u]; i ; i = pre[i])
        {
            int v = to[i];
            if (dis[v] > dis[u] + w[i])
            {
                dis[v] = dis[u] + w[i];
                if (not inq[v])
                {
                    q.push (v);
                    inq[v] = true;
                    times[v] ++;
                    if (times [v] > n) return false;
                }
            }
        }
    }
    return false; //没有负环
}
```

##### 差分约束

如果 `a + b <= c` 则 `addEdge (b, a, c);`  
添加超级源点0后 `spfa (0)` 判断负环  
有负环则无解，无负环则有解  
其中的一组解是dis[]

### 最小生成树

kruskal

```cpp
// 并查集

int fa[maxn];
inline void init ()
{
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
    }
}

int find (int x)
{
    if (fa[x] != x)
    {
        return fa[x] = find (fa[x]);
    }
    return fa[x];
}

// kruskal
struct Edge{
    int u, v;
    int w;
    friend bool operator < (Edge a, Edge b)
    {
        return a.w < b.w;
    }
};
Edge es[maxn];

inline int kruskal ()
{
    int tot = 0;
    int res = 0;
    sort (es + 1, es + m + 1)
    for (int i = 1; i <= m; i++)
    {
        int u_root = find (es[i].u);
        int v_root = find (es[i].v);
        if (u_root != v_root)
        {
            fa[v_root] = u_root;
            tot ++;
            res += es[i].w;
        }
        if (tot == n - 1)
        {
            return res;
        }
    }
    return -1;
}
```

### tarjan
#### 强连通分量
```cpp
int cnt;
int to[maxn], pre[maxn], last[maxn];
inline void addEdge (int u, int v)
{
    cnt ++;
    to[cnt] = v;
    pre[cnt] = last[u];
    last[u] = cnt;
}

int stk[maxn], spos;
bool ins[maxn];
int scc[maxn], gpos;
int dfn[maxn], low[maxn], npos;

void tarjan (int now, int fa)
{
    dfn[now] = low[now] = ++npos;
    stk[++spos] = now;
    ins[now] = true;

    for (int i = last[now]; i ; i = pre[i])
    {
        int t = to[i];
        if (t == fa) continue;
        if (not dfn[t])
        {
            tarjan (t, now); 
            low[now] = min (low[now], low[t]);
        }
        else if (ins[t])
        {
            low[now] = min (low[now], dfn[t]);
        }
    }
    if (dfn[now] == low[now])
    {
        ++ gpos;
        do {
            scc[stk[spos]] = gpos;
            sz[gpos] ++;
            ins[stk[spos]] = 0;
            spos --;
        } while (stk[spos] != now);
    }
}

```

#### 缩点

```cpp
int cnt;
int to[maxn], pre[maxn], last[maxn];
inline void addEdge (int u, int v)
{
    cnt ++;
    to[cnt] = v;
    pre[cnt] = last[u];
    last[u] = cnt;
}

int dfn[maxn], low[maxn], npos;
int scc[maxn], gpos;
int s[maxn], spos;


```

#### 割点

#### 桥

### lca

### 树链剖分

## 基础
### 高精度 *毒瘤*
```cpp

```
### 二分答案


## DP
### 线性DP

### 背包

### 树形DP

### 区间DP

### 状压DP

### 插头DP



## 字符串