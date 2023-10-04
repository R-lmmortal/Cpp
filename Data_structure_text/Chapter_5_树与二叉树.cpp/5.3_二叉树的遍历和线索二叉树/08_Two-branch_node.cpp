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

int TwobranchNode(BiTree t)
{
    if (t == NULL)
        return 0;
    else if (t->lchild && t->rchild)
        return TwobranchNode(t->lchild) + TwobranchNode(t->rchild) + 1;
    else
        return TwobranchNode(t->lchild) + TwobranchNode(t->rchild);
}

// ABD###CE##F##
int main()
{
    BiTree t;
    cout << "请输入二叉树的元素：";
    PreCreateTree(t);
    cout << "该二叉树的双分支节点个数为" << TwobranchNode(t) << "个" << endl;
    return 0;
}