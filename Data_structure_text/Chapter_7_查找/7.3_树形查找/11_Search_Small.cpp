// 编写一个算法，在一棵有n个结点的、随机建立起来的二叉排序树上
// 查找第k（1<=k<=n）小的元素，并返回指向该节点的指针
// 二叉排序树的每个结点中新增一个count乘员，保存以该结点为根的子树上的结点个数
#include <bits/stdc++.h>
using namespace std;

// 树相关数据结构
typedef char BiElemType;
typedef struct BiTNode
{
    BiElemType data;
    struct BiTNode *lchild, *rchild;
    int count;
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

BiTNode *Search_Small(BiTree t, int k)
{
    if (k < 1 || k > t->count)
        return NULL; // k合法条件
    if (t->lchild == NULL)
    { // 左子树空的情况
        if (k == 1)
            return t; // k=1就是根结点
        else
            Search_Small(t->rchild, k - 1); // k不等于1 就是到右子树中找第k-1小
    }
    else
    { // 左子树不为空
        if (t->lchild->count == k - 1)
            return t;
        if (t->lchild->count > k - 1)
            return Search_Small(t->lchild, k);
        if (t->lchild->count < k - 1)
            return Search_Small(t->lchild, k - (t->lchild->count));
    }
}
