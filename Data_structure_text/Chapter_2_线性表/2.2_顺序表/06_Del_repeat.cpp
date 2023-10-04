#include <bits/stdc++.h>
using namespace std;
#define MAX 50
struct sqlist
{
    int a[MAX] = {1, 2, 3, 3, 4, 5, 6, 7, 7, 7, 8, 9};
    int length = 12;
};

void Del_repeat(sqlist &L)
{
    int i, j;
    for (i = 0, j = 1; j < L.length; j++)
    {
        if (L.a[i] != L.a[j])
        {
            L.a[++i] = L.a[j];
        }
    }
    L.length = i + 1;
}

void Del_repeat2(sqlist &L)
{
    int i, j;
    for (i = 1, j = 1; j < L.length; j++)
    {
        if (L.a[j] != L.a[j - 1])
        {
            L.a[i] = L.a[j];
            i++;
        }
    }
    L.length = i;
}

int main()
{
    sqlist L;
    for (int i = 0; i < L.length; i++)
        cout << L.a[i] << " ";
    cout << endl;
    cout << "--------------------------------------" << endl;
    Del_repeat2(L);
    for (int i = 0; i < L.length; i++)
        cout << L.a[i] << " ";
}