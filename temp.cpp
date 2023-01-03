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

int k;
int n;
int a[maxn];

int main()
{
    deque<int> q;
    for (int i = 1; i <= n; i++)
    {
        while (not q.empty() and i - q.back() > k) q.pop_back();
        while (not q.empty() and a[q.front()] >= a[i]) q.pop_front();
        q.push_front(i);
        if (i >= k)
        {
            cout << a[q.back()] << endl;
        }
    }
    
    return 0;
}