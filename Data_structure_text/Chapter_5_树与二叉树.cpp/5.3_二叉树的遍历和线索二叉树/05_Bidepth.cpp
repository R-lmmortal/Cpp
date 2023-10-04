#include <bits/stdc++.h>
using namespace std;

// 树相关数据结构
typedef char BiElemType;
typedef struct BiTNode
{
    BiElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

// 顺序列队相关数据结构
#define MAX 50
typedef BiTree ElemType;
typedef struct
{
    ElemType data[MAX];
    int f, r;
} SeQueue;

// 初始化列队
void InitQueue(SeQueue &q)
{
    q.f = q.r = -1;
}

// 判空
int IsEmpty(SeQueue q)
{
    if (q.f == q.r)
        return 1;
    else
        return 0;
}

// 入队
void EnQueue(SeQueue &q, ElemType x)
{
    if (q.r == MAX - 1)
    {
        cout << "队满";
    }
    else
    {
        q.data[++(q.r)] = x;
    }
}

// 出队
void DeQueue(SeQueue &q, ElemType &x)
{
    if (IsEmpty(q))
    {
        cout << "队空";
    }
    else
    {
        x = q.data[++(q.f)];
    }
}

// 先序创建二叉树
void PreCreateTree(BiTree &t)
{
    char ch;
    ch = getchar();
    if (ch == '#')
        t = NULL;
    else
    {
        t = (BiTNode *)malloc(sizeof(BiTNode));
        t->data = ch;
        t->lchild = NULL;
        t->rchild = NULL;
        PreCreateTree(t->lchild);
        PreCreateTree(t->rchild);
    }
}

int Bidepth(BiTree t)
{
    SeQueue q;
    InitQueue(q);
    if (!t)
        return 0;
    int L = 0; // 每一层最后一个的索引
    int ans = 0;
    BiTree p;
    EnQueue(q, t);
    while (q.f < q.r)
    {
        DeQueue(q, p);
        if (p->lchild)
            EnQueue(q, p->lchild);
        if (p->rchild)
            EnQueue(q, p->rchild);
        if (q.f == L)
        {
            ans++;
            L = q.r;
        }
    }
    return ans;
}

// abd##e##cf###
int main()
{
    BiTree t;
    cout << "请输入二叉树的元素：";
    PreCreateTree(t);
    cout << "树的高度为：" << Bidepth(t) << endl;
    return 0;
}