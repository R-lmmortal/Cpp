// 折半查找非递归算法
#include <bits/stdc++.h>
using namespace std;

typedef struct
{
    int data[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    int length = 8;
} SST;

int BisearchRec(SST s, int Key, int low, int high)
{
    if (low > high)
        return 0;
    int mid = (low + high) / 2;
    if (Key > s.data[mid])
        return BisearchRec(s, Key, mid + 1, high);
    else if (Key < s.data[mid])
        return BisearchRec(s, Key, low, mid - 1);
    else
        return mid;
}

int main()
{
    SST s;
    cout << BisearchRec(s, 3, 1, 8) << endl;
    return 0;
}