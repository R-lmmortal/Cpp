// 设计一个算法，判断一个数据列是否构成小根堆
#include <bits/stdc++.h>
using namespace std;

int IsMinHeap(int a[], int len)
{
    if (len % 2 == 0)
    { // len为偶数，有一个单分支结点
        if (a[len / 2] > a[len])
            return 0; // 判断单分支结点
        for (int i = len / 2 - 1; i >= 1; i--)
        { // 判断所有双分支结点
            if (a[i] > a[2 * i] || a[i] > a[2 * i + 1])
                return 0;
        }
    }
    else
    { // len为奇数，没有单分支结点
        for (int i = len / 2; i >= 1; i--)
        { // 判断所有双分支结点
            if (a[i] > a[2 * i] || a[i] > a[2 * i + 1])
                return 0;
        }
    }
    return 1;
}

int main()
{
    int a[8] = {1, 1, 3, 2, 5, 4, 0};
    cout << IsMinHeap(a, 6) << endl;
    return 0;
}
/*
               1
        3            2
    5      4     0
*/