#include <bits/stdc++.h>
using namespace std;

typedef char BiElemType;
typedef struct BiTNode
{
    BiElemType data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
    int tag;
} BiTNode, *BiTree;

// 栈相关数据结构
#define MAX 50
typedef BiTree ElemType;
typedef struct stacknode
{
    ElemType data[MAX];
    int top;
} Sqstack;

// 初始化栈
void InitStack(Sqstack &s)
{
    s.top = -1;
}

// 判空
bool IsEmpty(Sqstack s)
{
    if (s.top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// 入栈
int Push(Sqstack &s, ElemType x)
{
    if (s.top == MAX - 1)
        return 0;
    s.data[++s.top] = x;
    return 1;
}

// 出栈
int Pop(Sqstack &s, ElemType &x)
{
    if (s.top == -1)
        return 0;
    x = s.data[s.top--];
    return 1;
}

// 取栈顶
int GetTop(Sqstack s, ElemType &x)
{
    if (IsEmpty(s))
        return 0;
    x = s.data[s.top];
    return 1;
}

void PreCreatTree(BiTree &t)
{
    char ch;
    ch = getchar();
    if (ch == '#')
        t = NULL;
    else
    {
        t = (BiTNode *)malloc(sizeof(BiTNode));
        t->data = ch;
        t->tag = 0;
        t->lchild = NULL;
        t->rchild = NULL;
        PreCreatTree(t->lchild);
        PreCreatTree(t->rchild);
    }
}

void PostOrder(BiTree t)
{
    Sqstack s;
    InitStack(s);
    BiTree p = t;
    while (p || !IsEmpty(s))
    {
        if (p)
        {
            Push(s, p);
            p = p->lchild;
        }
        else
        {
            GetTop(s, p);
            if (p->rchild && p->rchild->tag == 0)
            {
                p = p->rchild;
            }
            else
            {
                Pop(s, p);
                cout << p->data;
                p->tag = 1;
                p = NULL;
            }
        }
    }
}
// abd##e##c##
int main()
{
    BiTree t;
    cout << "请输入二叉树的元素：";
    PreCreatTree(t);
    PostOrder(t);
    return 0;
}