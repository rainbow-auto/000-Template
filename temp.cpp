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

const int maxn = 1000005;

int nxt[maxn];
int s[maxn];
int p[maxn];

int n, m;

int main()
{
    n = Reader::read();
    for (int i = 1; i <= n; i++) cin >> p[i];

    m = Reader::read();
    for (int i = 1; i <= m; i++) cin >> s[i];

    for (int i = 2, j = 0; i <= n; i++)
    {
        while (j and p[j + 1] != p[i]) j = nxt[j];
        if (p[j + 1] == p[i]) j++;
        nxt[i] = j;
    }

    for (int i = 1, j = 0; i <= m; i++)
    {
        while (j and p[j + 1] != s[i]) j = nxt[j];
        if (p[j + 1] == s[i]) j++;
        if (j == n)
        {
            cout << i - n << " ";
            j = nxt[j];
        }   
    }

    return 0;
}