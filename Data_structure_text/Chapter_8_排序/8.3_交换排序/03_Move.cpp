// 设计把所有奇数移到偶数前的算法
#include <bits/stdc++.h>
using namespace std;

void Move(int a[], int n)
{
    int i = 0, j = n - 1;
    while (i < j)
    {
        while (i < j && a[i] % 2 == 1)
            i++;
        while (i < j && a[j] % 2 == 0)
            j--;
        if (i < j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
}

int main()
{
    int a[10] = {7, 5, 9, 2, 6, 4, 3, 8, 1};
    Move(a, 9);
    for (int i = 0; i < 9; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}