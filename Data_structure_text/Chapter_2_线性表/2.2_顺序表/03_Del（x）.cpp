#include <bits/stdc++.h>
using namespace std;
#define MAX 50
typedef int ElemType;
struct sqlist
{
    ElemType a[MAX] = {5, 2, 0, 1, 3, 1, 4, 1, 1, 4};
    int length = 10;
};

void Del_x(sqlist &L, ElemType x)
{
    int k = 0;
    for (int i = 0; i < L.length; i++)
    {
        if (L.a[i] == x)
            k++;
        else
            L.a[i - k] = L.a[i];
    }
    L.length = L.length - k;
}

int main()
{
    sqlist L;
    ElemType x;
    Del_x(L, 4);
    for (int i = 0; i < L.length; i++)
    {
        cout << L.a[i] << " ";
    }
}