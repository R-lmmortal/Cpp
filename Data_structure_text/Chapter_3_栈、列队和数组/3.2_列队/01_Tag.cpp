#include <bits/stdc++.h>
using namespace std;

#define MAX 10
typedef struct
{
    int data[MAX];
    int f, r, tag;
} squeue;

bool push(squeue &s, int x)
{
    if (s.f == s.r && s.tag == 1)
    {
        cout << "队满 进队失败" << endl;
        return false;
    }
    else
    {
        s.data[s.r] = x;
        s.r = (s.r + 1) % MAX;
        s.tag = 1;
        return true;
    }
}

int pop(squeue &s, int &x)
{
    if (s.f == s.r && s.tag == 0)
    {
        cout << "队空 出队失败" << endl;
        return 0;
    }
    else
    {
        x = s.data[s.f];
        s.f = (s.f + 1) % MAX;
        s.tag = 0;
        return 1;
    }
}

void print(squeue s)
{
    for (int i = 0; i < MAX; i++)
    {
        cout << s.data[s.f] << " ";
        s.f = (s.f + 1) % MAX;
    }
    cout << endl;
}

int main()
{
    squeue s;
    s.f = 0, s.r = 0, s.tag = 0;
    for (int i = 0; i < 10; i++)
    {
        push(s, i);
    }
    cout << endl;
    print(s);
    // push(s, 0);
    // cout << "---------------------" << endl;
    // int x = 0;
    // for (int i = 0; i < 10; i++)
    // {
    //     pop(s, i);
    // }
    // cout << endl;
    // pop(s, x);
    // return 0;
}