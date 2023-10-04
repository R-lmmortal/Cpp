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

int NodeCount(BiTree t)
{
    if (t == NULL)
        return 0;
    else
        return NodeCount(t->lchild) + NodeCount(t->rchild) + 1;
}

// ABC##DE###FG#H###
int main()
{
    BiTree t;
    cout << "请输入二叉树的元素：";
    PreCreateTree(t);
    cout << "二叉树的总结点数为：" << NodeCount(t) << endl;
}
/*
         A
       /   \
      B     F
     / \   /
    C   D G
       /   \
      E     H
*/