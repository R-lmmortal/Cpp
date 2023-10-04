#include <bits/stdc++.h>
using namespace std;

typedef int DT; // DataType
// 定义一个链表节点
typedef struct qnode
{
    DT data;
    struct qnode *next;
} LinkListQ;
// 定义一个链列队
typedef struct
{
    LinkListQ *f;
    LinkListQ *r;
} LinkQueue;

// 初始化
void InitQueue(LinkQueue &q)
{
    q.f = q.r = (LinkListQ *)malloc(sizeof(LinkListQ)); // 建立链列队的头节点,并将头尾指针指向头节点
    q.f->next = NULL;                                   // 初始头指针的next域指向为空
}

// 判空
int EmptyQueue(LinkQueue q)
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

// 入队
void InQueue(LinkQueue &q, DT x)
{
    LinkListQ *s = (LinkListQ *)malloc(sizeof(LinkListQ)); // 生成新节点
    s->data = x;                                           // 将x存入新节点数据域
    s->next = NULL;                                        // 将新节点的next域指向空
    q.r->next = s;                                         // 将新节点插入链队之后
    q.r = s;                                               // 将尾指针指向队尾元素
}

// 出队
void DeQueue(LinkQueue &q, DT &x)
{
    if (EmptyQueue(q))
    {
        cout << "EmptyQueue" << endl;
    }
    else
    {
        LinkListQ *p = q.f->next; // 创建一个新的链列队指针指向头节点next域所指向的节点
        x = p->data;              // 队头元素赋值给x
        q.f->next = p->next;      // 队头指针重新指向队头
        if (q.r == p)
        {
            q.r = q.f; // 若原列队中只有一个节点，删除后列队为空
        }
        free(p); // 释放p中元素
    }
}

// 显示队中元素
void display(LinkQueue q)
{
    LinkListQ *p = q.f;
    cout << "此时从队头起各元素为：";
    while (p->next != NULL)
    {
        cout << p->next->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main()
{
    LinkQueue q;
    InitQueue(q);

    int n;
    cout << "请输入要入队元素的个数：";
    cin >> n;
    cout << "请输入要入队的元素：";
    for (int i = 0; i < n; i++)
    {
        DT x;
        cin >> x;
        InQueue(q, x);
    }
    display(q);

    cout << "请输入要出队元素的个数：";
    cin >> n;
    cout << "以下元素已出队：";
    for (int i = 0; i < n; i++)
    {
        DT x;
        DeQueue(q, x);
        cout << x << " ";
    }
    cout << endl;
    display(q);
}