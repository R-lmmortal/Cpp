#include <bits/stdc++.h>
using namespace std;

#define MaxSize 100
typedef int DT;

typedef struct stacknode
{
    DT data;
    struct stacknode *next;
} linkstack;

// 初始化链栈
linkstack *Initstack()
{
    linkstack *s;
    s = NULL;
    return s;
}

// 判断链栈是否空
int isEmpty(linkstack *s)
{
    if (s == NULL)
        return 1;
    else
        return 0;
}

// 进栈
int push(linkstack *&s, DT x)
{
    linkstack *p;
    p = (linkstack *)malloc(sizeof(linkstack)); // 生成新节点
    p->data = x;                                // 将x放入新节点的数据域
    p->next = s;                                // 将新节点的next指针指向栈顶所指向的地方
    s = p;                                      // 将新节点作为栈顶
    return 1;
}
/*
*&的类型是对指针的引用
如果传一个指针a的值给指针类型变量p，例如int*p =a
那么改变*p的值，*a的值会发生变化；但改变p的值，a的值不会改变
如果传一个指针a的值给指针引用类型变量p，例如int*& p=a
那么不仅改变*p的值，*a的值会发生变化；改变p本身的值，a的值也会发生改变。
引用类型相当于给变量起了别名，例如int &a=b，a是一个整形引用类型变量，也相当于b的别名。
那么改变b的值，a的值也会改变。
*/

// 出栈
int pop(linkstack *&s, DT *x)
{
    linkstack *p;
    if (isEmpty(s))
    {
        cout << "栈空，不能出栈" << endl;
        return 0;
    }
    else
    {
        *x = s->data; // 栈顶元素赋给x
        p = s;
        s = s->next;
        free(p);
        return 1;
    }
}

// 取栈顶元素
int GetTop(linkstack *s, DT &x)
{
    if (isEmpty(s))
    {
        cout << "栈空，不能出栈" << endl;
        return 0;
    }
    else
    {
        x = s->data;
        return 1;
    }
}

// 显示栈内元素
void Showstack(linkstack *s)
{
    linkstack *p = s;
    if (p == NULL)
        cout << "栈空" << endl;
    else
    {
        cout << "从栈顶起栈中各元素为" << endl;
        while (p != NULL)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
}

int main()
{
    linkstack *s = Initstack();
    int n;
    cout << "请输入想入栈元素的个数" << endl;
    cin >> n;
    cout << "请输入想要入栈的元素" << endl;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        push(s, x);
    }
    Showstack(s);

    int j;
    cout << "请输入想出栈的个数" << endl;
    cin >> j;
    cout << "下列元素已出栈" << endl;
    for (int i = 0; i < j; i++)
    {
        DT x;
        pop(s, &x);
        cout << x << " ";
    }
    cout << endl;

    cout << "出栈后";
    Showstack(s);
    return 0;
}