#include <bits/stdc++.h>
using namespace std;

// 树相关数据结构
typedef char BiElemType;
typedef struct BiTNode
{
    BiElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

int pos = 0;
BiTree CreateTree(char a[], char b[], int start, int end)
{
    if (start <= end)
    {
        BiTree t = (BiTree)malloc(sizeof(BiTNode));
        t->data = a[pos];
        int i;
        for (i = start; i <= end; i++)
        {
            if (b[i] == t->data)
                break;
        }
        pos++; // 定位根节点
        t->lchild = CreateTree(a, b, start, i - 1);
        t->rchild = CreateTree(a, b, i + 1, end);
        return t;
    }
    return NULL;
}

void PostOrder(BiTree t)
{
    if (t)
    {
        PostOrder(t->lchild);
        PostOrder(t->rchild);
        cout << t->data << " ";
    }
}

int main()
{
    char a[] = {'A', 'B', 'D', 'E', 'C', 'F'}; // 先序序列
    char b[] = {'D', 'B', 'E', 'A', 'F', 'C'}; // 中序序列
    BiTree t = CreateTree(a, b, 0, 5);
    cout << "后序序列为：" << endl;
    PostOrder(t);
    return 0;
}
/*       A
       /   \
      B     C
     / \   /
    D   E F
*/