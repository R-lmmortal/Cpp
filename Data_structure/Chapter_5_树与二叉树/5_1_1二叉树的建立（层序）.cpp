#include <bits/stdc++.h>
using namespace std;

typedef char BiElemType;
typedef struct BiTNode
{
    BiElemType data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
} BiTNode, *BiTree;

typedef struct tag
{             // tag结构体是辅助队列使用的
    BiTree p; // 树上的某一个节点的地址
    struct tag *pnext;
} tag_t, *ptag_t;

void LevelCreateBiTree(BiTree tree)
{
    tree = NULL;                       // tree指向树的根节点并设为空
    BiTree pnew;                       // 用来指向新申请的树节点
    ptag_t phead = NULL, ptail = NULL; // 列队的队头指针、队尾指针
    ptag_t listpnew = NULL;            // 列队指向新节点的指针
    ptag_t pcur;                       // 记录当前要往哪个节点下入新节点

    char c; // 输入要插入的 如abcdefghijk
    while ((c = getchar()))
    {
        if (c == '\n')
        {
            break; // 读到换行就结束
        }
        // calloc：申请空间并对空间进行初始化赋值为0，calloc申请的空间大小是两个参数直接相乘
        pnew = (BiTree)calloc(1, sizeof(BiTNode));
        pnew->data = c;                              // 数据放进去
        listpnew = (ptag_t)calloc(1, sizeof(tag_t)); // 给队列节点申请空间
        listpnew->p = pnew;
        if (NULL == tree)
        {                     // 如果是树的第一个节点
            tree = pnew;      // tree指向树的根节点
            phead = listpnew; // 第一个节点即是队头，也是队尾
            ptail = listpnew;
            pcur = listpnew; // pcur要指向要进入树的元素的父亲元素
        }
        else
        {
            ptail->pnext = listpnew; // 否则让元素先入队列
            ptail = listpnew;
            if (NULL == pcur->p->lchild)
            {                           // 接下来把节点放入树中
                pcur->p->lchild = pnew; // pcur->p左孩子为空，就放入左孩子
            }
            else if (NULL == pcur->p->rchild)
            {
                pcur->p->rchild = pnew; // pcur->p右孩子为空，就放入右孩子
                pcur = pcur->pnext;     // 当前节点左右孩子都满了，pcur就指向下一个
            }
        }
    }
}

// 改进版
void LevelCreateBiTree2(BiTree &tree)
{
    tree = NULL;
    BiTree pnew;
    ptag_t phead = NULL, ptail = NULL;
    ptag_t listpnew = NULL;
    ptag_t pcur = NULL;

    char c;
    cout << "请输入要插入的元素：";
    while ((c = getchar()) != '\n')
    {
        if (c == '#')
        {
            pnew = NULL;
        }
        else
        {
            pnew = (BiTree)calloc(1, sizeof(BiTNode));
            pnew->data = c;
        }

        if (pnew != NULL)
        {
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
}

int main()
{
    BiTree tree;
    LevelCreateBiTree(tree);
    return 0;
}