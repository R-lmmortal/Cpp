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

void resolve(Linklist &L, Linklist &L2)
{
    L2 = (Linklist)malloc(sizeof(LNode));
    L2->next = NULL;
    Linklist r1 = L->next, r2 = L2, p;
    while (r1 != NULL && r1->next != NULL)
    {
        p = r1->next;
        r1->next = p->next;
        r2->next = p;
        p->next = NULL;
        r2 = p;
        r1 = r1->next;
    }
}

void reverse(Linklist &L)
{
    Linklist p = L->next, r;
    L->next = NULL;
    while (p)
    {
        r = p->next;
        p->next = L->next;
        L->next = p;
        p = r;
    }
}

void revolve_reverse(Linklist &L, Linklist &L1)
{
    L1 = (Linklist)malloc(sizeof(LNode));
    L1->next = NULL;
    Linklist r = L, p = L->next, q;
    while (p)
    {
        r->next = p;
        r = p;
        p = p->next;
        if (p != NULL)
            q = p->next;
        p->next = L1->next;
        L1->next = p;
        p = q;
    }
    r->next = NULL;
}

int main()
{
    Linklist L, L1;
    tail_insert(L);
    print_list(L);
    cout << "--------------------";
    cout << endl;
    // resolve(L, L2);
    // print_list(L);
    // print_list(L2);
    // cout << "--------------------";
    // cout << endl;
    // reverse(L2);
    // print_list(L);
    // print_list(L2);
    revolve_reverse(L, L1);
    print_list(L);
    print_list(L1);
    return 0;
}