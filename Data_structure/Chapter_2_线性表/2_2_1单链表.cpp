#include <bits/stdc++.h>
using namespace std;

typedef int DataType;
typedef struct LNone
{                       // 定义单链表的节点类型
    DataType data;      // 定义节点的数据域
    struct LNone *next; // 定义节点的指针域
} LNone, *Linklist;     // LNone*是结构体指针，和Linklist完全等价

// 初始化单链表
Linklist InitList()
{
    Linklist h = (Linklist)malloc(sizeof(LNone)); // 动态分配一个节点空间
    h->next = NULL;                               // 头节点设置为空，代表空链表
    return h;
}

// 头插法建表
void CreateListH(Linklist &h, int n)
{
    Linklist s;
    cout << "请输入" << n << "个整数：";
    for (int i = 0; i < n; i++)
    {
        s = (Linklist)malloc(sizeof(LNone));
        cin >> s->data;
        s->next = h->next;
        h->next = s;
    }
}

// 尾插法建表(需要用到一个新的指针——>尾指针last)
void CreateListL(Linklist &h, int n)
{
    Linklist s, last = h; // s为指向新节点的指针----last指针始终指向尾节点，一开始没有插入数据所以指向头节点
    cout << "请输入" << n << "个整数：";
    for (int i = 0; i < n; i++)
    {
        s = (Linklist)malloc(sizeof(LNone)); // 生成新节点
        cin >> s->data;                      // 输入新节点的数据
        s->next = NULL;                      // 将新节点的指针域设为空
        last->next = s;                      // 将新节点插入尾表
        last = s;                            // 将last指针指向表位节点
    }
    // last->next = NULL;     //可在循环里每次循环把新节点的next指针设为空，也可以循环结束后将尾节点的next设为空
}

// 求表长操作
int LengthList(Linklist h)
{
    Linklist p = h;
    int j = 0;
    while (p->next != NULL)
    {
        p = p->next;
        j++;
    }
    cout << "当前表的长度为：" << j << endl;
    return 1;
}

// 查找操作
// 1按位置查找
int GetElem(Linklist h, int i)
{
    int j = 0;
    // Linklist p = h;
    while (h->next != NULL)
    {
        h = h->next;
        j++;
        if (j == i)
        {
            DataType x = h->data;
            cout << "位置" << i << "处的元素值为：" << x << endl;
            return 1;
        }
    }
    cout << "没有第" << i << "个位置的元素"
         << "\n";
    return 0;
}

// 2按值查找
void Locate(Linklist h, DataType x)
{
    Linklist p = h->next;
    int j = 1;
    while (p != NULL && p->data != x)
    {
        p = p->next;
        j++;
    }
    if (p != NULL)
        cout << "已找到值为" << x << "的元素,位置为" << j;
    else
        cout << "没有值为" << x << "的元素";
}

// 插入操作
int InsList(Linklist h, int i, DataType x)
{
    Linklist p, s;
    int j = 0;
    p = h;
    while (p != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (p == NULL)
    {
        cout << "位置" << i << "不合法" << endl;
        return 0;
    }
    else
    {
        s = (Linklist)malloc(sizeof(LNone));
        s->data = x;
        s->next = p->next;
        p->next = s;
        cout << "已在位置" << i << "插入元素" << x << endl;
        return 1;
    }
}

// 删除操作
void DelList(Linklist h, int i)
{
    int j = 0;
    DataType x;
    Linklist p, s;
    p = h;
    while (p->next != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (p->next != NULL && j == i - 1)
    {
        s = p->next;
        x = s->data;
        p->next = s->next;
        free(s);
        cout << "已删除位置为" << i << "，元素值为" << x << "的元素" << endl;
    }
    else
        cout << "位置" << i << "不合法" << endl;
}

// 输出表中元素
void DispList(Linklist h)
{
    cout << "当前顺序表中元素为：";
    Linklist p;  // 建立一个新指针
    p = h->next; // 让新指针指向头节点的next域
    while (p != NULL)
    {                           // 当p指针不指向空时
        cout << p->data << " "; // 输出链表数据域的值
        p = p->next;            // 输出后p指针指向下一个数据
    }
    cout << "\n";
}

int main()
{
    Linklist h = InitList(); // 初始化单链表头节点

    // 测试建表   头插法/尾插法--------------------------------------
    int n;
    cout << "请输入你想插入数据的个数：";
    cin >> n;
    // CreateListH(h, n);
    CreateListL(h, n);
    LengthList(h);
    DispList(h);

    // 测试查找操作------------------------------------------------
    cout << "请输入想要查找的位置：";
    cin >> n;
    GetElem(h, n);
    cout << "请输入想要查找的值：";
    cin >> n;
    Locate(h, n);

    // 测试插入操作-------------------------------------------------
    // int i;
    // DataType x;
    // cout << "请输入你想插入元素的位置：";
    // cin >> i;
    // cout << "请输入你想插入的元素：";
    // cin >> x;
    // InsList(h, i, x);
    // LengthList(h);
    // DispList(h);

    // 测试删除操作------------------------------------------------
    // cout << "请输入你想删除元素的位置：";
    // cin >> i;
    // DelList(h, i);
    // LengthList(h);
    // DispList(h);
}
