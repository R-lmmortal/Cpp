#include <bits/stdc++.h>
using namespace std;

#define MaxSize 10
typedef int DT;

typedef struct
{
    DT data[MaxSize];
    int top;
} sqstack;

// 初始化栈
void InitStack(sqstack &s)
{
    s.top = -1;
}

// 判断栈是否为空
bool IsEmpty(sqstack s)
{
    if (s.top == -1) // 栈空
        return true;
    else // 栈满
        return false;
}

// 判断栈是否满
bool IsFull(sqstack &s)
{
    if (s.top == MaxSize - 1) // 栈满
        return true;
    else // 栈空
        return false;
}

// 入栈
int push(sqstack &s, DT x)
{
    if (IsFull(s))
    {
        cout << "栈满，不能进栈!" << endl;
        return 0;
    }
    else
    {
        s.top++;
        s.data[s.top] = x; // s.data[++s.top]=x;
        return 1;          // 先自加再赋值
    }
}

// 出栈
int pop(sqstack &s, DT &x)
{
    if (IsEmpty(s))
    {
        cout << "栈空，不能出栈!" << endl;
        return 0;
    }
    else
    {
        x = s.data[s.top];
        s.top--;  // x=s.data[s.top--];
        return 1; // 先赋值再自减
    }
}

// 读取栈顶元素
int GetTop(sqstack s, DT &x)
{
    if (IsEmpty(s))
        return 0;
    x = s.data[s.top];
    cout << "栈顶元素为：" << x << endl;
    return 1;
}

int main()
{
    sqstack s;    // 建立栈
    InitStack(s); // 初始化栈
    // 元素进栈
    int n;
    cout << "请输入要入栈的个数：" << endl;
    cin >> n;
    cout << "请输入你想入栈的元素" << endl;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        push(s, x);
    }
    DT x;
    GetTop(s, x);
    // 元素出栈
    int j;
    cout << "请输入想出栈的个数" << endl;
    cin >> j;
    for (int i = 0; i < j; i++)
    {
        int z;
        pop(s, z);
        cout << z << " ";
    }
    // while (!IsEmpty(s))
    // {
    //     int x;
    //     pop(s, x);
    //     cout << x << " ";
    // }
}