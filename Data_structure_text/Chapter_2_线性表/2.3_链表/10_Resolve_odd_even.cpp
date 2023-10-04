#include <bits/stdc++.h>
using namespace std;

typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *Linklist;

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

void new_resolve_odd_even(Linklist &L, Linklist &L2)
{
    L2 = (Linklist)malloc(sizeof(LNode));
    L2->next = NULL;
    Linklist r1 = L->next, r2 = L2, s;
    while (r1 != NULL && r1->next != NULL)
    {
        s = r1->next;
        r1->next = s->next;
        r2->next = s;
        s->next = NULL;
        r2 = s;
        r1 = r1->next;
    }
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

int main()
{
    Linklist L, L2;
    tail_insert(L);
    print_list(L);
    cout << "-------------------------------";
    cout << endl;
    resolve(L, L2);
    print_list(L);
    print_list(L2);
    return 0;
}
