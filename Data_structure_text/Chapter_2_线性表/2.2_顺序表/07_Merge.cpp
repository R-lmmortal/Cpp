#include <bits/stdc++.h>
using namespace std;
#define MAX 50
struct sqlist
{
    int data[MAX];
    int length;
};

bool merge(sqlist a, sqlist b, sqlist &c)
{
    if (c.length < a.length + b.length)
        return false;
    int i = 0, j = 0, k = 0;
    while (i < a.length && j < b.length)
    {
        if (a.data[i] <= b.data[j])
            c.data[k++] = a.data[i++];
        else
            c.data[k++] = b.data[j++];
    }
    while (i < a.length)
    {
        c.data[k++] = a.data[i++];
    }
    while (j < b.length)
    {
        c.data[k++] = b.data[j++];
    }
    c.length = k;
    return true;
}

int main()
{
    sqlist a = {{2, 3, 4, 6, 7}, 5};
    sqlist b = {{3, 4, 4}, 3};
    sqlist c;
    c.length = a.length + b.length;
    for (int i = 0; i < a.length; i++)
        cout << a.data[i] << " ";
    cout << endl;
    for (int i = 0; i < b.length; i++)
        cout << b.data[i] << " ";
    cout << endl;
    if (!merge(a, b, c))
        cout << "merge false" << endl;
    else
    {
        for (int i = 0; i < c.length; i++)
        {
            cout << c.data[i] << " ";
        }
        cout << endl;
    }
}

// #define LEN 50
// struct sqlist1
// {
//     int a[MAX] = {2, 3, 4, 6, 7}; // 1,2, 2, 4,5, 6,6, 8,11
//     int length = 5;               // i=8   j=4
// };
// struct sqlist2
// {
//     int b[LEN] = {3, 4, 4, 11};
//     int length = 4;
// };

// bool ListInsert(sqlist1 &L, int i, int e)
// {
//     for (int j = L.length; j >= i; j--)
//     {
//         L.a[j] = L.a[j - 1];
//     }
//     L.a[i - 1] = e; // 放入要插入元素
//     L.length++;     // 顺序表长度加1
//     return true;
// }

// bool merge(sqlist1 &L, sqlist2 Q)
// {
//     int i, j;
//     for (i = 0, j = 0; i < L.length && j < Q.length; i += 2, j++)
//     {
//         if (L.a[i] > Q.b[j])
//         {
//             ListInsert(L, i + 1, Q.b[j]);
//         }
//         else
//         {
//             ListInsert(L, i + 2, Q.b[j]);
//         }
//     }
//     return true;
// }

// int main()
// {
//     sqlist1 L;
//     sqlist2 Q;
//     merge(L, Q);
//     for (int i = 0; i < L.length; i++)
//         cout << L.a[i] << " ";
//     return 0;
// }