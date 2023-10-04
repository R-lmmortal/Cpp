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

// 列队相关数据结构
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

// 递归实现
// 前序遍历   也叫深度优先遍历
void PreOrder(BiTree p)
{
    if (p != NULL)
    {
        cout << p->data;     // 打印根节点
        PreOrder(p->lchild); // 打印左子树
        PreOrder(p->rchild); // 打印右子树
    }
}

// 中序遍历
void InOrder(BiTree p)
{
    if (p != NULL)
    {
        InOrder(p->lchild); // 打印左子树
        cout << p->data;    // 打印根节点
        InOrder(p->rchild); // 打印右子树
    }
}

// 后序遍历
void PostOrder(BiTree p)
{
    if (p != NULL)
    {
        PostOrder(p->lchild); // 打印左子树
        PostOrder(p->rchild); // 打印右子树
        cout << p->data;      // 打印根节点
    }
}

// 层序遍历  也叫广度优先遍历
void LevelOrder(BiTree T)
{
    LinkQueue q;
    InitQueue(q);
    BiTree p;      // 存储出队的节点
    EnQueue(q, T); // 把根入队
    while (!IsEmpty(q))
    {
        DeQueue(q, p);
        cout << p->data;
        if (p->lchild)
        {
            EnQueue(q, p->lchild);
        }
        if (p->rchild)
        {
            EnQueue(q, p->rchild);
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
    InOrder(tree);
    cout << endl;
    cout << "---------PostOrder---------" << endl;
    PostOrder(tree);
    cout << endl;
    cout << "---------LevelOrder---------" << endl;
    LevelOrder(tree);
    return 0;
}
