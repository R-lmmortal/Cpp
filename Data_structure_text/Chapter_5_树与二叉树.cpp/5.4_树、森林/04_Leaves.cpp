// 编程求以孩子兄弟表示法储存的森林的叶子结点树
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

int Leaves(BiTree t)
{
    // 空结点返回0
    if (t == NULL)
        return 0;
    // 孩子为空即左孩子域为空 为叶子结点 结果加1还要加上右兄弟子树的叶子结点
    if (t->child == NULL)
        return 1 + Leaves(t->rbro);
    // 有孩子 结果为左孩子子树和右孩子子树的叶子结点之和
    else
        return Leaves(t->child) + Leaves(t->rbro);
}

int main()
{
    BiTree t;
    cout << "请输入要插入的元素：";
    PreCreateTree(t);
    cout << "森林的叶子结点数为：" << Leaves(t) << endl;
    return 0;
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