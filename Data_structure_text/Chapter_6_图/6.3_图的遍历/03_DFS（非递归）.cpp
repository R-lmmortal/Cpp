// 图的深度优先搜索DFS算法的非递归算法（图采用邻接表形式）
#include <bits/stdc++.h>
using namespace std;

// 图相关数据结构
#define MaxVertexNum 100 // 最大顶点数

// 边表结点
typedef struct ArcNode
{
    int adjvex;              // 该弧所指向的顶点的位置
    struct ArcNode *nextarc; // 指向下一条弧的指针
    // InfoType info;  网的边权值
} ArcNode;

// 顶点表结点
typedef int VerTexType;
typedef struct VNode
{
    VerTexType data;   // 顶点表信息
    ArcNode *firstarc; // 指向第一条依附该结点的弧指针
} VNode, AdjList[MaxVertexNum];

// 图的数据结构
typedef struct
{
    AdjList vertices;   // 邻接表
    int vexnum, arcnum; // 图的顶点数和弧数
} ALGraph;              // AdjoinListGraph是以邻接表存储的图类型

// 栈相关数据结构
#define MAX 50
typedef struct stacknode
{
    char data[MAX];
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
int Push(Sqstack &s, int x)
{
    if (s.top == MAX - 1)
        return 0;
    s.data[++s.top] = x;
    return 1;
}

// 出栈
int Pop(Sqstack &s, int &x)
{
    if (s.top == -1)
        return 0;
    x = s.data[s.top--];
    return 1;
}

// 访问结点函数
void visit(int v)
{
    cout << v << " ";
}

// 获取顶点的第一个邻接顶点函数
int FirstNeighbour(ALGraph &G, int v)
{
    int vIndex = v - 'A'; // 假设顶点用字母 'A', 'B', 'C' 等表示
    ArcNode *p = G.vertices[vIndex].firstarc;

    if (p != NULL)
    {
        return p->adjvex;
    }
    else
    {
        return -1; // 没有邻接顶点
    }
}

// 获取下一个邻接顶点
int NextNeighbour(ALGraph &G, int v, int w)
{
    int vIndex = v - 'A'; // 假设顶点用字母 'A', 'B', 'C' 等表示
    ArcNode *p = G.vertices[vIndex].firstarc;

    while (p != NULL && p->adjvex != w)
    {
        p = p->nextarc;
    }

    if (p != NULL && p->nextarc != NULL)
    {
        return p->nextarc->adjvex;
    }
    else
    {
        return -1; // 没有下一个邻接顶点
    }
}

void DFS_Non_RC(ALGraph &G, int v)
{
    // 初始化栈
    Sqstack s;
    InitStack(s);

    // 初始化Visited数组
    bool visited[G.vexnum + 1];
    for (int i = 0; i < G.vexnum; i++)
        visited[i] = false;

    // 顶点压入栈中
    Push(s, v);
    // 顶点已经被压入过 更新visited数组
    visited[v] = true;

    // 退栈
    while (!IsEmpty(s))
    {
        // 将栈顶出栈并保存在v中
        Pop(s, v);
        // 访问该结点 访问的顺序就是DFS顺序
        visit(v);
        // 访问所有邻接结点
        for (int w = FirstNeighbour(G, v); w >= 0; w = NextNeighbour(G, v, w))
        {
            // 没有进过栈的话进栈
            if (!visited[w])
            {
                Push(s, w);
                // 更新visited值
                visited[w] = true;
            }
        }
    }
}
