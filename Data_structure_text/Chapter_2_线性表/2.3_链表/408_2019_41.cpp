#include <bits/stdc++.h>
using namespace std;

typedef int ElemType;
typedef struct LNone
{
    ElemType data;
    struct LNone *next;
} LNone, *Linklist;

void list_tail_insert(LNone *&L)
{
    L = (LNone *)malloc(sizeof(LNone));
    L->next = NULL;
    Linklist s, r = L;
    ElemType x;
    cin >> x;
    while (x != 9999)
    {
        s = (LNone *)malloc(sizeof(LNone));
        s->data = x;
        r->next = s;
        r = s;
        cin >> x;
    }
    r->next = NULL;
}

void print_list(Linklist L)
{
    L = L->next;
    while (L != NULL)
    {
        cout << L->data << " ";
        L = L->next;
    }
    cout << endl;
}

// 找链表中间节点（双指针法），并设置好L2链表
void find_middle(Linklist L, Linklist &L2)
{
    L2 = (LNone *)malloc(sizeof(LNone)); // 第二条链表头节点
    Linklist pcur, ppre;                 // 双指针法
    ppre = pcur = L->next;
    while (pcur)
    {
        pcur = pcur->next;
        if (pcur == NULL)
        { // 为了防止pcur为NULL
            break;
        }
        pcur = pcur->next;
        if (pcur == NULL)
        { // 为了使偶数个时，ppre依旧指向a1,a2…a6中的a3节点
            break;
        }
        ppre = ppre->next;
    }
    L2->next = ppre->next; // 由L2头节点指向后面一半链表
    ppre->next = NULL;     // 前一半链表的最后一个节点的next要设为空
}

void reverse(Linklist L2)
{
    Linklist r, s, t;
    r = L2->next;
    if (r == NULL)
    {
        return; // 链表为空
    }
    s = r->next;
    if (s == NULL)
    {
        return; // 链表只有一个节点
    }
    t = s->next;
    while (t)
    {
        s->next = r; // 原地逆置
        r = s;       // 以下3句是三个指针同时往后走一步
        s = t;
        t = t->next;
    }
    s->next = r;
    L2->next->next = NULL; // 逆置后，原有链表的第一个节点变成最后一个节点，因此next要为NULL
    L2->next = s;          // s是链表的第一个节点，L2指向它
}

void merge(Linklist L, Linklist L2)
{
    Linklist pcur, p, q;
    pcur = L->next; // pcur始终指向组合后链表的链表尾
    p = pcur->next; // p用来遍历L链表
    q = L2->next;   // q指向L2第一个节点,用来遍历L2链表
    while (p != NULL && q != NULL)
    {
        pcur->next = q;
        q = q->next;
        pcur = pcur->next;
        pcur->next = p;
        p = p->next;
        pcur = pcur->next;
    }
    // 任何一个链表都可能剩一个节点，放进来即可
    if (p != NULL)
    {
        pcur->next = p;
    }
    if (q != NULL)
    {
        pcur->next = q;
    }
}

int main()
{
    Linklist L;          // 链表头
    list_tail_insert(L); // 输入数据可以为 1 2 3 4 5 9999
    print_list(L);       // 链表打印
    // 寻找中间节点，并返回第二条链表
    Linklist L2;
    find_middle(L, L2); // 只有一个节点的时候L2中没有节点
    cout << "-------------------------" << endl;
    cout << "L ：";
    print_list(L);
    cout << "L2：";
    print_list(L2);
    cout << "-------------------------" << endl;
    reverse(L2);
    cout << "reverse L2：";
    print_list(L2);
    cout << "-------------------------" << endl;
    merge(L, L2);
    free(L2);
    cout << "merge L L2：";
    print_list(L);
    return 0;
}
