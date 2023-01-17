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
#include <queue>

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

ll exgcd (ll a, ll b, ll& x, ll& y)
{
    if (not b)
    {
        x = 1, y = 0;
        return a;
    }    
    ll res = exgcd (b, a % b, y, x);
    y -= x * (a / b);
    return res;
}

int main ()
{
    return 0;
}