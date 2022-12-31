#include <iostream>
using namespace std;

const int maxn = 1e6 + 10;

int n;
int a[maxn];

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

int main ()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    QuickSort (1, n);

    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}