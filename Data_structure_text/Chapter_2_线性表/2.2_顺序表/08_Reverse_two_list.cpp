#include <bits/stdc++.h>
using namespace std;
#define MAX 50
struct sqlist
{
    int data[MAX] = {1, 2, 3, 4, 5, 6, 7};
    int length = 7;
};

void Reverse_a_b(sqlist &L, int a, int b) // 4,6,5,7  a=0 b=3 i=1
{
    for (int i = a; i <= (a + b) / 2; i++)
    {
        int temp = L.data[i];
        L.data[i] = L.data[a + b - i];
        L.data[a + b - i] = temp;
    }
}

void print(sqlist L)
{
    for (int i = 0; i < L.length; i++)
    {
        cout << L.data[i] << " ";
    }
    cout << endl;
}

void change(sqlist &L, int m, int n)
{
    cout << "整个逆置：";
    Reverse_a_b(L, 0, m + n - 1);
    print(L);
    cout << "前n个逆置：";
    Reverse_a_b(L, 0, n - 1);
    print(L);
    cout << "后m个逆置即最终结果：";
    Reverse_a_b(L, n, m + n - 1);
    print(L);
}

int main()
{
    sqlist L;
    change(L, 3, 4);
    return 0;
}