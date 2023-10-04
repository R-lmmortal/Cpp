// 求先序遍历序列中第k个节点的值
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

int i = 1;
char ch;
char PreNode(BiTree t, int k)
{
    if (t == NULL)
        return '#';
    if (i == k)
        return t->data;
    i++;
    ch = PreNode(t->lchild, k);
    if (ch != '#')
        return ch;
    ch = PreNode(t->rchild, k);
    return ch;
}

int main()
{
    BiTree t;
    cout << "请输入二叉树的元素：";
    PerCreateBiTree(t);
    int k;
    cout << "请输入想查找元素的先序位置：";
    cin >> k;
    cout << "该节点元素为：" << PreNode(t, k) << endl;
    return 0;
}

/*       A
       /   \
      B     C
     / \   / \
    D   E F   G
  ABD##E##CF##G##
  输入5，结果为C
*/