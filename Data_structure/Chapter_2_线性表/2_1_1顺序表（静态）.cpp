#include <bits/stdc++.h>
using namespace std;

// 静态分配顺序表------------------------------------------------------------------------------------------

// 定义顺序表
#define MAXLEN 100 // 静态分配长度
typedef int ElemType;
typedef struct
{
    ElemType data[MAXLEN]; // 静态分配：用数组存放元素
    int length;            // 顺序表的当前长度
} Seqlist1;

// 初始化静态分配顺序表
void InitList(Seqlist1 &L)
{
    for (int i = 0; i < MAXLEN; i++)
    {
        L.data[i] = 0; // 将所有数据元素设置为默认初始值
        L.length = 0;  // 顺序表的初始长度为0
    }
}

// 顺序表的建立
void CreateList(Seqlist1 &L, int n)
{
    int i;
    cout << "请输入" << n << "个整数：";
    for (i = 0; i < n; i++)
    {
        cin >> L.data[i];
        L.length = n;
    }
}

// 插入操作 ListInsert(&L,i,e):在表L的第i个位置上插入指定元素e
bool ListInsert(Seqlist1 &L, int i, ElemType e)
{ // 注：由于插入操作会使L改变所以要用引用
    // 判断i位置是否合法
    if (i < 1 || i > L.length + 1)
    {
        cout << "你插入的位置不在有效空间内" << endl;
        return false;
    }
    // 判断存储空间是否已满
    if (L.length == MAXLEN)
    {
        cout << "储存空间已满" << endl;
        return false;
    }

    // 判断完毕实现插入操作------------------------------------

    // 把后面的元素依次往后移动，空出位置，来放入要插入的元素
    for (int j = L.length; j >= i; j--)
    {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e; // 放入要插入元素
    L.length++;        // 顺序表长度加1
    cout << "已在第" << i << "个位置增加元素，增加的元素值为" << e << "\n";
    return true;
}

// 删除操作
bool ListDelete(Seqlist1 &L, int i, ElemType e)
{
    // 判断i位置是否合法
    if (i < 1 || i > L.length)
    {
        cout << "你插入的位置不在有效空间内" << endl;
        return false;
    }
    e = L.data[i - 1];
    for (int j = i; j < L.length; j++)
    {
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    cout << "已删除第" << i << "个元素,删除的元素值为" << e << "\n";
    return true;
}

// 查找操作
//  1按位置查找
int GetElem(Seqlist1 L, int i)
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
int Locate(Seqlist1 L, ElemType e)
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

// 打印顺序表
void PrintList(Seqlist1 L)
{
    cout << "当前顺序表中元素为：";
    int i;
    for (i = 0; i < L.length; i++)
    {
        cout << L.data[i] << " ";
    }
    cout << "\n";
}

int main()
{
    Seqlist1 L;
    int n;
    cout << "请输入你想插入元素的个数：";
    cin >> n;
    CreateList(L, n);
    PrintList(L);
    //----------------------------------------
    int i;
    cout << "请输入你想插入的位置：";
    cin >> i;
    ElemType e;
    cout << "请输入你想插入的数：";
    cin >> e;
    ListInsert(L, i, e);
    PrintList(L);
    //----------------------------------------
    cout << "请输入你想删除的位置：";
    cin >> i;
    ListDelete(L, i, e);
    PrintList(L);
    //----------------------------------------
    cout << "请输入你想查找元素的位置：";
    cin >> i;
    GetElem(L, i);
    cout << "请输入你想查找的元素：";
    cin >> e;
    Locate(L, e);
}
