// 对于树中每个元素值为x的节点，删去以它为根的子树，并释放相应的空间
#include <bits/stdc++.h>
using namespace std;

typedef char BiElemType;
typedef struct BiTNode
{
    BiElemType data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
} BiTNode, *BiTree;

void PerCreateBiTree(BiTree &T)
{
    BiElemType ch;
    ch = getchar();
    if (ch == '#')
        T = NULL;
    else
    {
        T = (BiTree)calloc(1, sizeof(BiTNode));
        T->data = ch;
        T->lchild = NULL;
        T->rchild = NULL;
        PerCreateBiTree(T->lchild);
        PerCreateBiTree(T->rchild);
    }
}

// 递归释放节点
void Release(BiTree &t)
{
    if (!t)
        return;
    Release(t->lchild);
    Release(t->rchild);
    free(t);
}

void DelNode(BiTree &t, char x)
{
    if (t == NULL)
        return;
    if (t->data == x)
    {
        Release(t);
        t = NULL;
    }
    if (t != NULL)
    {
        DelNode(t->lchild, x);
        DelNode(t->rchild, x);
    }
}

void PreOrder(BiTree t)
{
    if (t)
    {
        cout << t->data << " ";
        PreOrder(t->lchild);
        PreOrder(t->rchild);
    }
}

int main()
{
    BiTree t;
    cout << "请输入二叉树的元素：";
    PerCreateBiTree(t);
    cout << endl;
    cout << "二叉树的先序遍历为：";
    PreOrder(t);
    cout << endl;
    char x;
    cout << "请输入要删除的元素值：";
    cin >> x;
    DelNode(t, x);
    cout << "删除后二叉树的先序遍历为：";
    PreOrder(t);
    return 0;
}
/*       A
       /   \
      B     C
     / \   / \
    D   E F   G
  ABD##E##CF##G##

*/