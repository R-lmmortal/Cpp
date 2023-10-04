// 设计一个算法，从大到小输出二叉排序树中所有值不小于k的关键值
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

void OutPut(BiTree t, char k)
{
    if (t == NULL)
        return;
    if (t->rchild != NULL)
        OutPut(t->rchild, k);
    if (t->data >= k)
        cout << t->data << " ";
    if (t->lchild != NULL)
        OutPut(t->lchild, k);
}

int main()
{
    BiTree t;
    cout << "请输入二叉树的元素：";
    PreCreateTree(t);
    cout << endl;
    OutPut(t, 'E');
    return 0;
}

/*
                      F
             E                H
        C                 G       I
    A       D
       B
       先序：6531#2##4###87##9##
             FECA#B##D###HG##I##
*/