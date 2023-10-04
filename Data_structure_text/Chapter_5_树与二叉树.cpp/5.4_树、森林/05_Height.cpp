// 以孩子兄弟链表为储存结构，请设计递归算法求树的深度
#include <bits/stdc++.h>
using namespace std;

typedef char BiElemType;
typedef struct BiTNode
{
    BiElemType data;
    struct BiTNode *child; // 左孩子
    struct BiTNode *rbro;  // 右兄弟
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
        t->child = NULL;
        t->rbro = NULL;
        PreCreateTree(t->child);
        PreCreateTree(t->rbro);
    }
}

int Height(BiTree t)
{
    int m, n;
    if (t == NULL)
        return 0;
    else
    {
        m = Height(t->child);
        n = Height(t->rbro);
        if (m > n)
            return (m + 1);
        else
            return (n + 1);
    }
}

int main()
{
    BiTree t;
    cout << "请输入二叉树的元素：";
    PreCreateTree(t);
    cout << "树的深度为：" << Height(t) << endl;
}
/*       A               A           F
       /   \            / \         /
      B     F          B   C       G
     / \   /          / \
    D   C G          D   E
     \               此森林的叶子结点为4
      E
  ABD#E##C##FG###
*/