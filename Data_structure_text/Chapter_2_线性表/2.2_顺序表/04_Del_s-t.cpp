#include <bits/stdc++.h>
using namespace std;
#define MAX 50
struct sqlist
{
    int a[MAX] = {1, 2, 3, 3, 4, 5, 6, 7, 7, 7, 8, 9};
    int length = 12;
};

bool Del_s_t(sqlist &L, int s, int t)
{
    int i, j;
    if (s > t || L.length == 0)
        return false;
    for (i = 0; i < L.length && L.a[i] < s; i++)
        ;
    if (i > L.length)
        return false;
    for (j = i; j < L.length && L.a[j] <= t; j++)
        ;
    for (; j < L.length; i++, j++)
    {
        L.a[i + 1] = L.a[j - 1];
    }
    L.length = i + 1;
    return true;
}

bool Del_x(sqlist &L, int s, int t)
{
    if (L.length == 0)
        return false;
    int k = 0;
    for (int i = 0; i < L.length; i++)
    {
        if (L.a[i] > s && L.a[i] < t)
            k++;
        else
            L.a[i - k] = L.a[i];
    }
    L.length = L.length - k;
    return true;
}

int main()
{
    sqlist L;
    for (int i = 0; i < L.length; i++)
        cout << L.a[i] << " ";
    cout << endl;
    cout << "--------------------------------------" << endl;
    if (!Del_x(L, 3, 7))
        cout << "false" << endl;
    cout << "线性表长度为：" << L.length << endl;
    for (int i = 0; i < L.length; i++)
        cout << L.a[i] << " ";
    return 0;
}