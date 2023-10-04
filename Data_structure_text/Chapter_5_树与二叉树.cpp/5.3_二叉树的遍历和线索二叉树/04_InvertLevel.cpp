// 二叉树的自下而上，从左到右的层次遍历算法
#include <bits/stdc++.h>
using namespace std;

// 树相关数据结构
typedef char BiElemType;
typedef struct BiTNode
{
    BiElemType data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
} BiTNode, *BiTree;

typedef struct tag
{
    BiTree p;
    struct tag *pnext;
} tag_t, *ptag_t;

// 链列队相关数据结构
typedef BiTree ElemType;
typedef struct LinkNode
{
    ElemType data;
    struct LinkNode *next;
} LinkNode;
typedef struct
{
    LinkNode *f, *r;
} LinkQueue;

// 初始化
void InitQueue(LinkQueue &q)
{
    q.f = q.r = (LinkNode *)malloc(sizeof(LinkNode));
    q.f->next = NULL;
}

// 判空
bool IsEmpty(LinkQueue q)
{
    if (q.f == q.r)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// 入队
void EnQueue(LinkQueue &q, ElemType x)
{
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    q.r->next = s;
    q.r = s;
}

// 出队
void DeQueue(LinkQueue &q, ElemType &x)
{
    if (q.f == q.r)
    {
        cout << "EmptyQueue" << endl;
    }
    else
    {
        LinkNode *p = q.f->next;
        x = p->data;
        q.f->next = p->next;
        if (p == q.r)
        {
            q.r = q.f;
        }
        free(p);
    }
}

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

void Invertlevel(BiTree t)
{
    Sqstack s;
    InitStack(s);
    LinkQueue q;
    InitQueue(q);
    BiTree p;
    if (t)
    {
        EnQueue(q, t);
        while (!IsEmpty(q))
        {
            DeQueue(q, p);
            Push(s, p);
            if (p->lchild)
            {
                EnQueue(q, p->lchild);
            }
            if (p->rchild)
            {
                EnQueue(q, p->rchild);
            }
        }
        while (!IsEmpty(s))
        {
            Pop(s, p);
            cout << p->data;
        }
    }
}

int main()
{
    BiTree tree;
    cout << "请输入二叉树的元素：";
    LevelCreateBiTree(tree);
    Invertlevel(tree);
    return 0;
}