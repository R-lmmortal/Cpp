#include <bits/stdc++.h>
using namespace std;

#define MAXSIZE 100
typedef int DT;
typedef struct
{
    DT data[MAXSIZE];
    int f;
    int r;
} SeqQueue;

void InitQueue(SeqQueue &q)
{
    q.f = q.r = -1;
}

int EmptyQueue(SeqQueue q)
{
    if (q.f == q.r)
        return 1;
    else
        return 0;
}

int FillQueue(SeqQueue q)
{
    if (q.r == MAXSIZE - 1)
        return 1;
    else
        return 0;
}

void push(SeqQueue &q, DT x)
{
    if (FillQueue(q))
    {
        cout << "队满";
    }
    else
    {
        q.r += 1;
        q.data[q.r] = x;
        // q.data[++(q.r)=x]
    }
}

void pop(SeqQueue &q, DT &x)
{
    if (EmptyQueue(q))
    {
        cout << "队空";
    }
    else
    {
        q.f++;
        x = q.data[q.f];
        // x=q.data[++(q.f)]
    }
}

void print(SeqQueue q)
{
    cout << "此时队中的元素为：";
    for (int i = q.f + 1; i <= q.r; i++)
    {
        cout << q.data[i] << " ";
    }
    cout << endl;
}

int main()
{
    SeqQueue q;
    InitQueue(q);

    int n;
    cout << "请输入你要入队的个数：";
    cin >> n;
    cout << "请输入你要入队的元素：";
    for (int i = 0; i < n; i++)
    {
        DT x;
        cin >> x;
        push(q, x);
    }
    print(q);

    int m;
    cout << "请输入你要出队的个数：";
    cin >> m;
    cout << "下列元素已出队：";
    for (int i = 0; i < m; i++)
    {
        DT j;
        pop(q, j);
        cout << j << " ";
    }
    cout << endl;

    print(q);
}