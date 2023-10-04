#include <bits/stdc++.h>
using namespace std;

#define MAX 10
typedef struct
{
    int data[MAX];
    int top;
} Stack;

struct Queue
{
    int data[MAX];
    int f, r, tag;
};

bool enterqueue(Queue &q, int x)
{
    if (q.f == q.r && q.tag == 1)
    {
        cout << "队满 进队失败" << endl;
        return false;
    }
    else
    {
        q.data[q.r] = x;
        q.r = (q.r + 1) % MAX;
        q.tag = 1;
        return true;
    }
}

int outqueue(Queue &q, int &x)
{
    if (q.f == q.r && q.tag == 0)
    {
        cout << "队空 出队失败" << endl;
        return 0;
    }
    else
    {
        x = q.data[q.f];
        q.f = (q.f + 1) % MAX;
        q.tag = 0;
        return 1;
    }
}

bool enterstack(Stack &s, int x)
{
    if (s.top == MAX - 1)
    {
        cout << "栈满 进栈失败" << endl;
        return false;
    }
    else
    {
        s.data[++s.top] = x;
        return true;
    }
}

int outstack(Stack &s, int &x)
{
    if (s.top == -1)
    {
        cout << "栈空 进栈失败" << endl;
        return 0;
    }
    else
    {
        x = s.data[s.top--];
        return 1;
    }
}

void print(Queue q)
{
    for (int i = 0; i < MAX; i++)
    {
        cout << q.data[q.f] << " ";
        q.f = (q.f + 1) % MAX;
    }
    cout << endl;
}

void reverse(Stack &s, Queue &q)
{
    int x = 0;
    while (!(q.f == q.r && q.tag == 0))
    {
        outqueue(q, x);
        enterstack(s, x);
    }
    while (!(s.top == -1))
    {
        outstack(s, x);
        enterqueue(q, x);
    }
}

int main()
{
    Queue q;
    Stack s;
    q.f = 0, q.r = 0, q.tag = 0;
    s.top = -1;
    for (int i = 0; i < MAX; i++)
    {
        enterqueue(q, i);
    }
    print(q);
    cout << "---------------------" << endl;
    reverse(s, q);
    print(q);
    return 0;
}