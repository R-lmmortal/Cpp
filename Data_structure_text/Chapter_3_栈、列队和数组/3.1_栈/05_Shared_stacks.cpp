#include <bits/stdc++.h>
using namespace std;

#define MAX 50
typedef struct
{
    int data[MAX];
    int top[2];
} stack1;

stack1 s;

int push(int i, int x)
{
    if (i != 0 && i != 1)
    {
        cout << "无栈" << endl;
        return -1;
    }
    if (s.top[1] - s.top[0] == 1)
    {
        cout << "栈满" << endl;
        return -1;
    }
    if (i = 0)
    {
        s.data[++s.top[0]] = x;
    }
    else
    {
        s.data[--s.top[1]] = x;
    }
    return 1;
}

int pop(int i)
{
    if (i != 0 && i != 1)
    {
        cout << "无栈" << endl;
    }
    if (i = 0)
    {
        if (s.top[0] == -1)
        {
            cout << "0号栈栈空" << endl;
            return -1;
        }
        return s.data[s.top[0]--];
    }
    else
    {
        if (s.top[1] == MAX)
        {
            cout << "1号栈栈空" << endl;
            return -1;
        }
        return s.data[s.top[1]++];
    }
}

int main()
{
    s.top[0] = -1, s.top[1] = MAX;
    if (push(0, 1) != -1)
        cout << "0号栈进栈成功" << endl;
    int x = pop(0);
    if (x != -1)
        cout << "0号栈出栈元素为：" << x << endl;
    int y = pop(0);
    return 0;
}