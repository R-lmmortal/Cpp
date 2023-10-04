#include <bits/stdc++.h>
using namespace std;

// 动态分配顺序表------------------------------------------------------------------------------------------

// 定义顺序表
#define InitSize 10 // 动态分配时定义顺序表的初始长度为10
typedef int DataType;
typedef struct
{
    DataType *data; // 指示动态分配数组的指针
    int MaxSize;    // 顺序表的最大容量
    int length;     /*顺序表的当前长度*/
} Seqlist2;

// 初始化动态分配顺序表
void InitList2(Seqlist2 &L)
{
    // 用malloc动态分配内存  sizeof(DataType)是指自己定义的数据元素的大小 乘以 InitSize是指这个顺序表初始定义的长度
    L.data = (DataType *)malloc(sizeof(DataType) * InitSize);
    // c++的初始动态分配语句为：L.data=new DataType[InitSize];
    L.length = 0;
    L.MaxSize = InitSize;
}

//------------------------------------------------------------------------------------------------------

// 顺序表的建立
void CreateList(Seqlist2 &L, int n)
{
    int i;
    cout << "请输入" << n << "个整数"
         << "\n";
    for (i = 0; i < n; i++)
    {
        cin >> L.data[i];
        L.length = n;
    }
}

// 如果数组存满则可用函数增加动态数组长度
// 这就是和静态分配不同之处，静态分配满了之后不可增加
// 增加动态数组长度
void IncreaseSize(Seqlist2 &L, int len)
{
    int *p = L.data;
    L.data = (DataType *)malloc(sizeof(DataType) * (L.MaxSize + len));
    for (int i = 0; i < L.length; i++)
    {
        L.data[i] = p[i]; // 将数据复制到新区域
    }
    L.MaxSize = L.MaxSize + len; // 顺序表最大长度+len
    free(p);                     // 释放原来的内存
    cout << "已增加" << len << "长度" << '\n';
}

// 插入操作  ListInsert(&L,i,e):在表L的第i个位置上插入指定元素e
int ListInsert(Seqlist2 &L, int i, DataType e)
{
    if (i < 1 || i > L.length + 1)
        cout << "要插入的位置不在有效空间内";
    if (L.length >= L.MaxSize)
        cout << "你的储存空间已满";
    for (int j = L.length; j >= i; j--)
        L.data[j] = L.data[j - 1];
    L.data[i - 1] = e;
    L.length++;
    cout << "已在第" << i << "个位置增加元素，增加的元素值为" << e << "\n";
    return 1;
}

// 删除操作
int ListDelete(Seqlist2 &L, int i, DataType &e)
{
    if (i < 1 || i > L.length)
        cout << "要删除的位置不在有效空间内";
    e = L.data[i - 1];
    for (int j = i; j < L.length; j++)
        L.data[j - 1] = L.data[j];
    L.length--;
    cout << "已删除第" << i << "个元素,删除的元素值为" << e << "\n";
    return 1;
}

// 查找操作
// 1按位置查找
int GetElem(Seqlist2 L, int i)
{
    if (i < 1 || i > L.length)
    {
        cout << "当前表中没有第" << i << "个位置" << endl;
        return 0;
    }
    else
    {
        cout << "第" << i << "个位置的元素值为" << L.data[i - 1] << endl;
        return 1;
    }
}
// 2按值查找
int Locate(Seqlist2 L, DataType e)
{
    int i;
    for (i = 0; i < L.length; i++)
    {
        if (L.data[i] == e)
        {
            cout << "值为" << e << "的元素的位置为" << i + 1 << endl;
            return 1;
        }
    }
    cout << "该表中没有值为" << e << "的元素" << endl;
    return 0;
}

// 输出表中元素
void DisplayList(Seqlist2 L)
{
    int i;
    for (i = 0; i < L.length; i++)
        cout << L.data[i] << " ";
}
///*
// 主函数
int main()
{
    Seqlist2 L;   // 申明一个顺序表
    InitList2(L); // 调用初始化顺序表函数
    CreateList(L, 5);
    // IncreaseSize(L, 5);      //调用增加数组长度函数表示增加5个长度
    // ListInsert(L, 2, 8);
    // 删除操作要把e带回来
    // int e;
    // ListDelete(L, 1, e);
    // GetElem(L, 2);
    // Locate(L, 8);
    DisplayList(L);
}
//*/