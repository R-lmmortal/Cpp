#include <bits/stdc++.h>
using namespace std;
// 逆置线性表
#define MAX 50
struct sqlist
{
    int a[MAX] = {1, 2, 3, 4, 5, 6};
    int length = 6;
};
void reverse(sqlist &L)
{
    for (int i = 0; i < L.length / 2; i++)
    {
        int temp = L.a[i];
        L.a[i] = L.a[L.length - i - 1];
        L.a[L.length - i - 1] = temp;
    }
}

int main()
{
    sqlist L;
    for (int i = 0; i < L.length; i++)
        cout << L.a[i] << " ";
    cout << endl;
    cout << "--------------------------------------" << endl;
    reverse(L);
    for (int i = 0; i < L.length; i++)
        cout << L.a[i] << " ";
}