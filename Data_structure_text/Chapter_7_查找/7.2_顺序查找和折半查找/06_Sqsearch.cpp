// 若找到指定结点则将该结点和其前驱结点（若存在）交换
#include <bits/stdc++.h>
using namespace std;

int Sqsearch(int a[], int n, int k)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (a[i] == k)
            break;
    }
    if (i > 0 && i < n)
    {
        int t = a[i - 1];
        a[i - 1] = a[i];
        a[i] = t;
        return i - 1;
    }
    else
        return -1;
}

int main()
{
    int a[6] = {1, 2, 3, 4, 5};
    cout << Sqsearch(a, 5, 3) << endl;
    return 0;
}