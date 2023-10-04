// 编写双向冒泡排序算法，在正反两个方向交替进行扫描，
// 即第一趟把关键字最大的元素放在序列的最后面，第二趟把关键字最小的元素放在最前面，如此反复
#include <bits/stdc++.h>
using namespace std;

void Twoway_BubbleSort(int a[], int n)
{
    int low = 0, high = n - 1;
    bool flag = true;
    while (low < high && flag)
    { // flag=true
        flag = false;
        for (int i = low; i < high; i++)
        { // 从前向后交换
            if (a[i] > a[i + 1])
            {
                swap(a[i], a[i + 1]);
                flag = true;
            }
        }
        high--;
        for (int i = high; i > low; i--)
        { // 从后向前交换
            if (a[i] < a[i - 1])
            {
                swap(a[i], a[i - 1]);
                flag = true;
            }
        }
        low++;
    }
}

int main()
{
    int a[10] = {7, 5, 9, 2, 6, 4, 3, 8, 1};
    Twoway_BubbleSort(a, 9);
    for (int i = 0; i < 9; i++)
    {
        cout << a[i] << " ";
    }
}