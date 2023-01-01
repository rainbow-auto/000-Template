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

int main()
{
    string as, bs;
    cin >> as >> bs;

    vector<int> a;
    vector<int> b;
    for (int i = as.size() - 1; i >= 0; i--) a.push_back(as[i] - '0');     
    for (int i = bs.size() - 1; i >= 0; i--) b.push_back(bs[i] - '0');     
    
    vector<int> res = Add (a, b);
    for (int i = res.size() - 1; i >= 0; i--)
    {
        cout << res[i];
    }
    cout << endl;

    return 0;
}