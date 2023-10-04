#include <bits/stdc++.h>
using namespace std;

#define MAXSIZE 10
typedef int DT;
typedef struct
{
    DT data[MAXSIZE];
    int f;
    int r;
} CycleQueue;

// 和顺序列队的不同之处：
// 队满条件：          q.f==(q.r+1)%MAXSIZE;
// 队空条件仍为：      q.f==q.r;
// 队列中元素的个数为：(q.r-q.f+MAXSIZE)%MAXSIZE

void InitQueue(CycleQueue &q)
{
    q.f = q.r = 0;
}

int EmptyQueue(CycleQueue q)
{
    if (q.f == q.r)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int FillQueue(CycleQueue q)
{
    if ((q.r + 1) % MAXSIZE == q.f)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void EnQueue(CycleQueue &q, DT x)
{
    if (FillQueue(q))
    {
        cout << "队满";
    }
    else
    {
        q.data[q.r] = x;
        q.r = (q.r + 1) % MAXSIZE;
    }
}

void DeQueue(CycleQueue &q, DT &x)
{
    if (EmptyQueue(q))
    {
        cout << "队空";
    }
    else
    {
        x = q.data[q.f];
        q.f = (q.f + 1) % MAXSIZE;
    }
}

void print(CycleQueue q)
{
    int p = q.f;
    int num = (q.r - q.f + MAXSIZE) % MAXSIZE;
    if (p == q.r)
    {
        cout << "队空";
    }
    else
    {
        cout << "从队头起各元素为：";
        while (p != q.r)
        {
            cout << q.data[p] << " ";
            p++;
        }
        cout << endl;
        cout << "队列中元素的个数为：" << num << endl;
    }
}

int main()
{
    CycleQueue q;
    InitQueue(q);

    int n;
    cout << "请输入你要入队的个数：";
    cin >> n;
    cout << "请输入你要入队的元素：";
    for (int i = 0; i < n; i++)
    {
        DT x;
        cin >> x;
        EnQueue(q, x);
    }
    print(q);

    // int m;
    // cout << "请输入你要出队的个数：";
    // cin >> m;
    // cout << "下列元素已出队：";
    // for (int i = 0; i < m; i++)
    // {
    //     DT j;
    //     DeQueue(q, j);
    //     cout << j << " ";
    // }
    // cout << endl;

    // print(q);
}