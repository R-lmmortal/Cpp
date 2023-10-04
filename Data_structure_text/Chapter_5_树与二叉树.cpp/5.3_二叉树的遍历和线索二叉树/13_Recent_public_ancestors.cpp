// 编写算法找出二叉树中任意两个结点的最近公共祖先
#include <bits/stdc++.h>
using namespace std;

typedef char BiElemType;
typedef struct BiTNode
{
    BiElemType data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
} BiTNode, *BiTree;