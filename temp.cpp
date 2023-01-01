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

int main ()
{
    
    return 0;
}