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

int main()
{

    return 0;
}