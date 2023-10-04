// 求二叉树的宽度
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

// 列队相关数据结构
#define MAX 50
typedef BiTree ElemType;
typedef struct
{
    ElemType data[MAX];
    int level[10];
    int f, r;
} SeQueue;

// 初始化
void InitQueue(SeQueue &q)
{
    q.f = q.r = -1;
}

// 判空
int IsEmpty(SeQueue q)
{
    if (q.f == q.r)
        return 1;
    else
        return 0;
}

// 入队
void EnQueue(SeQueue &q, ElemType x)
{
    if (q.r == MAX - 1)
    {
        cout << "队满";
    }
    else
    {
        q.data[++(q.r)] = x;
    }
}

// 出队
void DeQueue(SeQueue &q, ElemType &x)
{
    if (IsEmpty(q))
    {
        cout << "队空";
    }
    else
    {
        x = q.data[++(q.f)];
    }
}

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

int Max_width(BiTree t)
{
    SeQueue q;
    InitQueue(q);
    BiTree p;         // 出队结点的指向
    int k;            // 保存出队的结点层次
    EnQueue(q, t);    // 根结点入队
    q.level[q.r] = 1; // 根结点的层次为1
    while (q.f < q.r)
    {                     // 当头指针小于尾指针时
        DeQueue(q, p);    // 保存出队结点
        k = q.level[q.f]; // 保存出队结点层次
        if (p->lchild != NULL)
        {
            EnQueue(q, p->lchild); // 左孩子入队
            q.level[q.r] = k + 1;  // 进队结点层次为出队结点层次加1
        }
        if (p->rchild != NULL)
        {
            EnQueue(q, p->rchild); // 右孩子进队
            q.level[q.r] = k + 1;  // 进队结点层次为出队结点层次加1
        }
    }
    int max = 0, i = 0, n; // 遍历时最大值更新，遍历下标，计算每层个数
    k = 1;
    while (i <= q.r)
    {
        n = 0; // 一开始每层默认0个
        while (i <= q.r && q.level[i] == k)
        {
            n++; // 每个层数递增
            i++; // 遍历的下标后移
        }
        k = q.level[i]; // 下一层的层次
        if (n > max)
            max = n;
    }
    return max;
}

int main()
{
    BiTree t;
    cout << "请输入二叉树的元素：";
    PerCreateBiTree(t);
    cout << "当前二叉树的最大宽度为：" << Max_width(t) << endl;
    return 0;
}
/*       A
       /   \
      B     C
     / \   / \
    D   E F   G
  ABD##E##CF##G##

*/