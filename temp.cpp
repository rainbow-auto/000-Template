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
int trie[maxn][26];
int cnt[maxn];
int id;

inline void insert (string s)
{
    int now = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int ch = s[i] - 'a';
        if (not trie[now][ch])
        {
            id++;
            trie[now][ch] = id;
        }
        now = trie[now][ch];
    }
}

inline void query(string s)
{
    int now = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int ch = s[i] - 'a';
        if (not trie[now][ch])
        {
            return 0;
        }
        now = trie[now][ch];
    }
    return cnt[now];
}

int main()
{
    
    return 0;
}