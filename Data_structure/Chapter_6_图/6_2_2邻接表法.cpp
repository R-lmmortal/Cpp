#include <bits/stdc++.h>
using namespace std;
// vertex 顶点    arc 弧    adjoin 邻接、毗邻
// vertices--vertex的复数

#define MaxVertexNum 100 // 最大顶点数

// 边表结点
typedef struct ArcNode
{
    int adjvex;              // 该弧所指向的顶点的位置
    struct ArcNode *nextarc; // 指向下一条弧的指针
    // InfoType info;  网的边权值
} ArcNode;

// 顶点表结点
typedef char VerTexType;
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

/*
        a——————————b          0 a|-->3|-->1|^
        |        / |          1 b|-->4|-->2|-->0|^
        |       /  |          2 c|-->4|-->2|-->1|^
        |     c    |          3 d|-->2|-->0|^
        |    /  \  |          4 e|-->2|-->1|^
        |   /    \ |
        |  /      \|
         d         e
【算法思想】
（1）输入总边数和顶点数
（2）建立顶点表
        依次输入点的信息存入顶点表中
        使每个表头结点的指针域初始化为NULL
（3）创建邻接表
        依次输入每条边依附的两个顶点
        确定两个顶点的序号i和j，建立边结点
        将此边结点分别插入到Vi和Vj对应的两个边链表头部
*/

// 查找顶点位置获取顶点序号的辅助函数
int LocateVex(ALGraph G, VerTexType v)
{
    for (int i = 0; i < G.vexnum; i++)
    {
        if (G.vertices[i].data == v)
            return i;
    }
    return -1; // 如果未找到，返回-1表示错误
}

// 采用邻接表表示法创建无向图
void CreateUDGraraph(ALGraph &G)
{
    ArcNode *p1, *p2;
    char v1, v2;
    cout << "请输入总顶点、总边数：";
    cin >> G.vexnum >> G.arcnum; // 输入总顶点、总边数
    cout << "请输入各结点值：";
    for (int i = 0; i < G.vexnum; i++)
    {                                  // 输入各点，构造表头结点
        cin >> G.vertices[i].data;     // 输入顶点值
        G.vertices[i].firstarc = NULL; // 初始化表头结点的指针域
    }
    cout << "请输入各边：" << endl;
    for (int k = 0; k < G.arcnum; k++)
    {                    // 输入各边，构造邻接表
        cin >> v1 >> v2; // 输入一条边依附的两个结点
        int i, j;
        // 查找顶点位置获取顶点序号
        for (i = 0; i < G.vexnum; i++)
        {
            if (G.vertices[i].data == v1)
                break;
        }
        for (j = 0; j < G.vexnum; j++)
        {
            if (G.vertices[j].data == v2)
                break;
        }
        p1 = (ArcNode *)malloc(sizeof(ArcNode)); // 生成一个新的边结点*p1
        p1->adjvex = j;                          // 邻接点序号为j
        p1->nextarc = G.vertices[i].firstarc;
        G.vertices[i].firstarc = p1; // 将新结点*p1插入顶点Vi的边表头部
        // 当建立有向网时后面部分可省略
        p2 = (ArcNode *)malloc(sizeof(ArcNode));
        p2->adjvex = i;
        p2->nextarc = G.vertices[j].firstarc;
        G.vertices[j].firstarc = p2; // 将新结点*p2插入顶点Vj的边表头部
    }
}

void PrintAL(ALGraph G)
{
    cout << "------------------------------" << endl;
    cout << "图G的邻接表如下:" << endl;
    for (int i = 0; i < G.vexnum; i++)
    {
        cout << i << " " << G.vertices[i].data << "|";
        ArcNode *current = G.vertices[i].firstarc;
        while (current != NULL)
        {
            cout << "-->" << current->adjvex; // cout << "--> " << G.vertices[current->adjvex].data;
            current = current->nextarc;
        }
        cout << "-->NULL" << endl;
    }
}

int main()
{
    ALGraph G;
    CreateUDGraraph(G);
    PrintAL(G);
    return 0;
}
/*
5 6                                      a——————————b          0 a|-->3|-->1|^
a b c d e                                |        / |          1 b|-->4|-->2|-->0|^
a b                                      |       /  |          2 c|-->4|-->3|-->1|^
a d                                      |     c    |          3 d|-->2|-->0|^
b c                                      |    /  \  |          4 e|-->2|-->1|^
b e                                      |   /    \ |
c d                                      |  /      \|
c e                                      d         e
0 a|-->3-->1-->NULL
1 b|-->4-->2-->0-->NULL
2 c|-->4-->3-->1-->NULL
3 d|-->2-->0-->NULL
4 e|-->2-->1-->NULL
*/