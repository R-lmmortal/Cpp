// 将二叉树的叶结点从左到右连成一个单链表，表头指针为head
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

BiTree head = (BiTree)malloc(sizeof(BiTNode)); // 全局头结点
BiTree pre = NULL;                             // 全局前驱结点
BiTree LinkNode(BiTree t)
{
    if (t)
    {
        LinkNode(t->lchild); // 将根结点的左孩子作为参数 一直递归向左延申
        if (t->lchild == NULL && t->rchild == NULL)
        { // 当找到叶子结点时
            if (pre == NULL)
            {             // 如果是第一个叶子结点
                head = t; // 头结点赋值
                pre = t;  // 保留前驱结点，前驱结点为当前的一个结点，保证后面再次遇到叶子结点时能够知道前驱结点是谁，并能够链接起来
            }
            else
            {                    // 若不是第一个叶子结点
                pre->rchild = t; // 就将前驱结点的右指针指向当前叶结点
                pre = t;         // 更新前驱结点
            }
        }
        LinkNode(t->rchild); // 左子树递归完成后向左递归右子树
        pre->rchild = NULL;  // 全部递归完成后将最后一个结点的右指针置空
    }
    return head;
}

int main()
{
    BiTree t;
    cout << "请输入二叉树的元素：";
    PerCreateBiTree(t);
    LinkNode(t);
    while (head)
    {
        cout << head->data << " ";
        head = head->rchild;
    }
    return 0;
}
/*       A
       /   \
      B     C
     / \   / \
    D   E F   G
  ABD##E##CF##G##
*/