// 在二叉树中查找值为x的节点，试编写算法打印值为x的结点的所有祖先，假设只为x的结点不多余一个
#include <bits/stdc++.h>
using namespace std;

typedef char BiElemType;
typedef struct BiTNode
{
    BiElemType data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
} BiTNode, *BiTree;

// 栈相关数据结构
#define MAX 50
typedef BiTree ElemType;
typedef struct stacknode
{
    ElemType t;
    int tag; // 节点左右孩子访问变量tag=0表示左孩子已经访问过，tag=1表示右孩子访问过
} Sqstack;

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

void Search(BiTree t, char x)
{
    // 初始化栈
    Sqstack s[10];
    int top = 0;
    while (t != NULL || top > 0)
    {
        // 从根节点开始向左延伸压入栈中并且结点的值不为x
        while (t != NULL && t->data != x)
        {
            s[++top].t = t;
            s[top].tag = 0;
            t = t->lchild;
        }
        // 如果找到了值为x的结点将栈中结点值输出
        if (t != NULL && t->data == x)
        {
            cout << "所有的祖先结点为：";
            for (int i = 1; i <= top; i++)
            {
                cout << s[i].t->data << " ";
            }
            break;
        }
        // 判断当前栈顶指针的结点的tag值为1的话依次退栈
        while (top != 0 && s[top].tag == 1)
        {
            top--;
        }
        // 当前栈顶不为0 将栈顶的tag值赋为1 结点指向该结点的右孩子
        if (top != 0)
        {
            s[top].tag = 1;
            t = s[top].t->rchild;
        }
    }
}

int main()
{
    BiTree t;
    cout << "请输入二叉树的元素：";
    PerCreateBiTree(t);
    char x;
    cout << "请输入要查找的元素值：";
    cin >> x;
    Search(t, x);
    return 0;
}
/*       A
       /   \
      B     C
     / \   / \
    D   E F   G
  ABD##E##CF##G##

*/