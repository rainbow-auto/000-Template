# Rainbow_auto 的模板

> powered by CTL 代码来自 acwing.com

## 火车头

```cpp
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

namespace Reader{
    int read ()
    {
        char c = getchar ();
        int x = 0, flag = 1;
        while (not isdigit (c)) { if (c == '-') flag = -1; c = getchar(); }
        while (isdigit (c)) { x = x * 10 + c - '0'; c = getchar(); }
        return x * flag;
    }
}

int main ()
{

    return 0;
}
```

## 基础算法

### 快速排序

```cpp
void QuickSort (int l, int r)
{
    if (l >= r)
    {
        return;
    }

    int mid = (l + r) >> 1;

    int x = a[mid];
    int i = l - 1;
    int j = r + 1;
    while (i < j)
    {
        do i ++; while (a[i] < x);
        do j --; while (a[j] > x);
        if (i < j) swap (a[i], a[j]);
    }

    QuickSort (l, j);
    QuickSort (j + 1, r);
}
```

### 二分

#### 整数二分

```cpp
int bsearch1 (int x) // lower_bound (x)
{
    int l = 1, r = n;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (a[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return l;
}

int bsearch2 (int x) // upper_bound (x) - 1
{
    int l = 1, r = n;
    while (l < r)
    {
        int mid = (l + r + 1) >> 1;
        if (a[mid] <= x) l = mid;
        else r = mid - 1;
    }
}
```

#### 浮点数二分

```cpp
double eps = 1e-9;
double bsearch_double (double x) // 求x的三次方根
{
    double l = min (x, -x), r = max (x, -x);
    while (r - l > eps)
    {
        double mid = (l + r) / 2;
        if (mid * mid * mid > x) l = mid;
        else r = mid;
    }
    return l;
}
```

### 高精度

#### 加法 (高精度+高精度)

```cpp
vector<int> Add (vector<int> a, vector<int> b)
{
    if (a.size() < b.size())
    {
        swap (a, b);
    }

    vector<int> res;
    int t = 0;
    for (int i = 0; i < a.size(); i++)
    {
        t += a[i];
        if (i < b.size()) t += b[i];
        res.push_back (t % 10);
        t /= 10;
    }

    if (t) res.push_back(t);

    return res;
}
```

#### 减法 (高精度 - 高精度)

```cpp
bool operator < (vector<int> a, vector<int> b)
{
    if (a.size() != b.size()) return a.size() < b.size();
    for (int i = a.size() - 1; i >= 0; i --)
    {
        if (a[i] != b[i])
        {
            return a[i] < b[i];
        }
    }
    return false; // a == b
}

vector<int> Sub(vector<int> a, vector<int> b)
{
    bool flag = false;
    if (a < b)
    {
        flag = true;
        swap (a, b);
    }

    vector<int> res;

    int t = 0;
    for (int i = 0; i < a.size(); i++)
    {
        t = a[i] - t;
        if (i < b.size()) t -= b[i];
        res.push_back((t + 10) % 10);
        if (t < 0)
        {
            t = 1;
        }
        else
        {
            t = 0;
        }
    }

    while (res.size() > 1 and res.back() == 0) res.pop_back ();
    if (flag)
    {
        res.push_back(-1); // 负数 -1
    }
    else
    {
        res.push_back(0); // 正数 0
    }
    return res;
}
```

#### 乘法 (高精度\*低精度)

```cpp
vector<int> mul (vector<int> a, int b)
{
    vector<int> res;
    int t = 0;
    for (int i = 0; i < a.size() or t; i ++)
    {
        if (i < a.size()) t += a[i] * b;
        res.push_back(t % 10);
        t /= 10;
    }
    while (res.size() > 1 and res.back() == 0) res.pop_back();
}

```

#### 除法 (高精度/低精度)

```cpp

vector<int> div (vector<int> a, int b, int& r)
{
    vector<int> res;
    r = 0;
    for (int i = 0; i < a.size(); i ++)
    {
        r = r * 10 + a[i];
        res.push_back (r / b);
        r %= b;
    }
    return res;
}

```
