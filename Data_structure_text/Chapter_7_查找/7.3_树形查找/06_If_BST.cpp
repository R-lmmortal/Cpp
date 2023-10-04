// 编写一个算法，判断给定的二叉树是否是二叉排序树
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

// 初始化前驱结点
int pre = INT_MIN;
int If_BST(BiTree t)
{
    if (t == NULL)
        return 1; // 判断树是否为空
    else
    {
        int b1 = If_BST(t->lchild); // 递归求左子树是否是二叉排序树
        if (b1 == 0 || ((t->data) - '0') <= pre)
            return 0;             // 判断左子树的值和当前结点的前驱结点值比较
        pre = (t->data) - '0';    // 将当前结点作为下一个前驱结点保存下来
        return If_BST(t->rchild); // 递归右子树的值
    }
}
int main()
{
    BiTree t;
    cout << "请输入二叉树的元素：";
    PreCreateTree(t);
    cout << If_BST(t) << endl;
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