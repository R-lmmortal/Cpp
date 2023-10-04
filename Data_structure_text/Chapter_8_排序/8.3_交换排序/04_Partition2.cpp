// 重新编写快速排序的划分算法，使之每次选区的枢轴值都是随机地从当前子表中选择
#include <bits/stdc++.h>
using namespace std;

int Partition2(int a[], int low, int high)
{
    int rand_Index = low + rand() % (high - low + 1);
    swap(a[rand_Index], a[low]);
    int i = low;
    int pivot = a[low];
    for (int j = low + 1; j <= high; j++)
    {
        if (a[j] < pivot)
        {
            swap(a[++i], a[j]);
        }
    }
    swap(a[low], a[i]);
    return i;
}