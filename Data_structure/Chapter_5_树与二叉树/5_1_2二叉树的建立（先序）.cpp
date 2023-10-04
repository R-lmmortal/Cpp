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
        T = (BiTree)calloc(1, sizeof(BiTNode)); // 新结点分配内存
        T->data = ch;                           // 赋值
        T->lchild = NULL;                       // 初始化左右孩子
        T->rchild = NULL;
        PerCreateBiTree(T->lchild); // 递归赋值
        PerCreateBiTree(T->rchild);
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

// abc##de#f##g###
int main()
{
    BiTree T;
    cout << "请输入要插入的元素：";
    PerCreateBiTree(T);
    PreOrder(T);
    return 0;
}
