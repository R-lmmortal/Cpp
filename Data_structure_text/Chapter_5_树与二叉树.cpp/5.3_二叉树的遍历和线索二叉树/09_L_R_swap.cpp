// 把二叉树B中所有节点的左、右子树进行交换
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

void Swap(BiTree &t)
{
    BiTree p;
    if (t)
    {
        Swap(t->lchild);
        Swap(t->rchild);
        p = t->lchild;
        t->lchild = t->rchild;
        t->rchild = p;
    }
}

void PreOrder(BiTree p)
{
    if (p != NULL)
    {
        cout << p->data;     // 打印根节点
        PreOrder(p->lchild); // 打印左子树
        PreOrder(p->rchild); // 打印右子树
    }
}

int main()
{
    BiTree t;
    cout << "请输入二叉树的元素：";
    PreCreateTree(t);
    cout << "---------交换前---------" << endl;
    PreOrder(t);
    cout << endl;
    cout << "---------交换后---------" << endl;
    Swap(t);
    PreOrder(t);
    return 0;
}
/*       A                       A
       /   \                   /   \
      B     C                 C     B
     / \   / \               / \   / \
    D   E F   G             G   F E   D
  ABD##E##CF##G##         ACE##D##BG##F##
*/