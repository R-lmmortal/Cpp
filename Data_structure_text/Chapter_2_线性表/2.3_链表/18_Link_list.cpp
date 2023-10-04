#include <bits/stdc++.h>
using namespace std;

typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNone, *Linklist;

void tail_insert(Linklist &L)
{
    L = (Linklist)malloc(sizeof(LNode));
    L->next = NULL;
    Linklist s, r = L;
    ElemType x;
    cin >> x;
    while (x != 9999)
    {
        s = (Linklist)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        cin >> x;
    }
    r->next = L;
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

void link_list(Linklist &L, Linklist &L1)
{
    Linklist r = L, r1 = L1;
    while (r->next != L)
    {
        r = r->next;
    }
    while (r1->next != L1)
    {
        r1 = r1->next;
    }
    r->next = L1->next;
    r1->next = L;
}

int main()
{
    Linklist L, L1;
    tail_insert(L);
    tail_insert(L1);
    print_list(L);
    print_list(L1);
    cout << "---------------------" << endl;
    link_list(L, L1);
    print_list(L);
}