// 设计一个算法，求出指定结点在给定二叉排序树中的层次
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

int Level(BiTree t, BiTNode *x)
{
    int n = 0;    // 初始化层数
    BiTree p = t; // 遍历树的结点
    if (t != NULL)
    { // 树不空的话 根节点层数+1
        n++;
        while (p->data != x->data)
        { // 循环条件是当是前结点的值不为要找的哪个值
            if (p->data > x->data)
                p = p->lchild; // 当前结点值大 结点指向左孩子
            else
                p = p->rchild; // 当前结点值小 结点指向右孩子
            n++;               // 同时层数+1
        }
    }
    return n; // 最后返回层数
}

int main()
{
    BiTree t;
    cout << "请输入二叉树的元素：";
    PreCreateTree(t);
    cout << endl;
    BiTNode *x = new BiTNode();
    cout << "请输入要查找的结点：";
    cin >> x->data;
    cout << "该结点在第" << Level(t, x) << "层" << endl;
    return 0;
}

/*
                      6
             5                8
        3                 7       9
    1       4
       2
       先序：6531#2##4###87##9##
             FECA#B##D###HG##I##
*/