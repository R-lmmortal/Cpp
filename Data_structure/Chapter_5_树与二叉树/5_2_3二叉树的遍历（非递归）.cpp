#include <bits/stdc++.h>
using namespace std;

// 树相关数据结构
typedef char BiElemType;
typedef struct BiTNode
{
    BiElemType data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
    int tag;
} BiTNode, *BiTree;

typedef struct tag
{
    BiTree p;
    struct tag *pnext;
} tag_t, *ptag_t;

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

// 层序创建二叉树
void LevelCreateBiTree(BiTree &tree)
{
    tree = NULL;
    BiTree pnew;
    ptag_t phead = NULL, ptail = NULL;
    ptag_t listpnew = NULL;
    ptag_t pcur;

    char c;
    cout << "请输入要插入的元素：";
    while ((c = getchar()))
    {
        if (c == '\n')
        {
            break;
        }
        pnew = (BiTree)calloc(1, sizeof(BiTNode));
        pnew->data = c;
        listpnew = (ptag_t)calloc(1, sizeof(tag_t));
        listpnew->p = pnew;
        if (NULL == tree)
        {
            tree = pnew;
            phead = listpnew;
            ptail = listpnew;
            pcur = listpnew;
        }
        else
        {
            ptail->pnext = listpnew;
            ptail = listpnew;
            if (NULL == pcur->p->lchild)
            {
                pcur->p->lchild = pnew;
            }
            else if (NULL == pcur->p->rchild)
            {
                pcur->p->rchild = pnew;
                pcur = pcur->pnext;
            }
        }
    }
}

// 前序遍历(非递归)
void PreOrder(BiTree T)
{
    Sqstack s;
    InitStack(s);
    BiTree p = T;
    while (p || !IsEmpty(s))
    {
        if (p)
        {
            cout << p->data;
            Push(s, p);
            p = p->lchild;
        }
        else
        {
            Pop(s, p);
            p = p->rchild;
        }
    }
}

// 中序遍历(非递归)
void InOrder2(BiTree T)
{
    Sqstack s;
    InitStack(s);
    BiTree p = T;
    while (p || !IsEmpty(s))
    {
        if (p)
        {
            Push(s, p);
            p = p->lchild;
        }
        else
        {
            Pop(s, p);
            cout << p->data;
            p = p->rchild;
        }
    }
}

// 后序遍历(非递归)
void PostOrder(BiTree T)
{
    Sqstack s;
    InitStack(s);
    BiTree p = T;
    while (p || !IsEmpty(s))
    {
        if (p)
        {
            Push(s, p);
            p = p->lchild;
        }
        else
        {
            GetTop(s, p); // p指向栈顶
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

int main()
{
    BiTree tree;
    LevelCreateBiTree(tree);
    cout << "---------PreOrder---------" << endl;
    PreOrder(tree);
    cout << endl;
    cout << "---------InOrder---------" << endl;
    InOrder2(tree);
    cout << endl;
    cout << "---------PostOrder---------" << endl;
    PostOrder(tree);
    cout << endl;
    return 0;
}