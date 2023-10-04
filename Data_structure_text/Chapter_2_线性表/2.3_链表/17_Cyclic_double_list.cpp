#include <bits/stdc++.h>
using namespace std;

typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next, *prior;
} LNone, *Linklist;

void tail_insert(Linklist &L)
{
    L = (Linklist)malloc(sizeof(LNode));
    L->prior = L;
    L->next = L;
    Linklist s, r = L;
    ElemType x;
    cin >> x;
    while (x != 9999)
    {
        s = (Linklist)malloc(sizeof(LNode));
        s->data = x;
        s->next = r->next;
        s->prior = r;
        r->next = s;
        r = s;
        cin >> x;
    }
    r->next = L;
    L->prior = r;
}

void print_list(Linklist L)
{
    LNode *s = L->next;
    while (s != L)
    {
        cout << s->data << " ";
        s = s->next;
    }
    cout << endl;
}

bool is_ok(Linklist L)
{
    LNode *p = L->next, *q = L->prior;
    while (p != q && q->next != p)
    {
        if (p->data == q->data)
        {
            p = p->next;
            q = q->prior;
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main()
{
    Linklist L;
    tail_insert(L);
    print_list(L);
    cout << "---------------------" << endl;
    if (is_ok(L))
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    return 0;
}