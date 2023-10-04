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

bool FuilyBinaryTree(BiTree t)
{
    SeQueue q;
    InitQueue(q);
    bool flag = true, ans = true;
    if (t == NULL)
        ans = true;
    if (!t->lchild && !t->rchild)
        ans = true;
    EnQueue(q, t);
    BiTree p;
    while (!IsEmpty(q))
    {
        DeQueue(q, p);
        if (!p->lchild) // 无左孩子
        {
            flag = false;
            if (p->rchild)
                ans = false;
        }
        else // 有左孩子
        {
            if (flag) // 之前不存在缺孩子的节点
            {
                EnQueue(q, p->lchild);
                if (p->rchild)
                    EnQueue(q, p->rchild);
                else
                    flag = false; // 表示无右孩子
            }
            else // 之前存在缺孩子的节点
            {
                ans = false;
            }
        }
    }
    if (ans)
        return true;
    return false;
}

// ABD##E##CF##G## 完全
// ABD###CE##F##  非完全
int main()
{
    BiTree t;
    cout << "请输入二叉树的元素：";
    PreCreateTree(t);
    if (FuilyBinaryTree(t))
        cout << "是完全二叉树" << endl;
    else
        cout << "不是完全二叉树" << endl;
    return 0;
}