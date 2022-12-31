# Rainbow_auto的模板
> powered by CTL 代码来自acwing.com

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

