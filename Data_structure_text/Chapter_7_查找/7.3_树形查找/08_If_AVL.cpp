// 利用二叉树遍历思想编写一个判断二叉树是否是平衡二叉树的算法
#include <bits/stdc++.h>
using namespace std;

// 树相关数据结构
typedef char BiElemType;
typedef struct BiTNode
{
    BiElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

void PreCreateTree(BiTree &t)
{
    BiElemType ch;
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

void If_AVL(BiTree t, int &balance, int &h)
{
    int bl = 0, br = 0, hl = 0, hr = 0;
    if (t == NULL)
    {
        h = 0;
        balance = 1;
    }
    else if (t->lchild == NULL && t->rchild == NULL)
    {
        h = 1;
        balance = 1;
    }
    else
    {
        If_AVL(t->lchild, bl, hl);
        If_AVL(t->rchild, br, hr);
        h = max(hl, hr) + 1;
        if (abs(hl - hr) <= 1)
        {
            balance = bl && br;
        }
        else
        {
            balance = 0;
        }
    }
}