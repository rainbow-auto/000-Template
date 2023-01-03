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
    stack<int> s;
    for (int i = 1; i <= n; i++)
    {
        while (not s.empty() and a[s.top()] >= a[i]) s.pop();
        if (s.empty()) cout << "-1 ";
        else cout << s.top() << " ";
        s.push(i);
    }

    return 0;
}