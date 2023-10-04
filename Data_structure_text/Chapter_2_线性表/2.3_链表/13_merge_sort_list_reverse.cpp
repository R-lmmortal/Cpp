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

void merge(Linklist &L, Linklist &L1)
{
    Linklist s = L, p = L->next, q = L1->next;
    while (p != NULL && q != NULL)
    {
        if (p->data > q->data)
        {
            L1->next = q->next;
            q->next = s->next;
            s->next = q;
            s = p;
            p = s->next;
            q = L1->next;
        }
        else if (p->data <= q->data && (p->next == NULL || q->data < p->next->data))
        {
            L1->next = q->next;
            q->next = p->next;
            p->next = q;
            s = q;
            p = s->next;
            q = L1->next;
        }
        else
        {
            s = p;
            p = s->next;
        }
    }
    if (q != NULL)
    {
        s->next = q;
    }
}

void reverse(Linklist &L)
{
    Linklist r, s, t;
    r = L->next;
    if (r == NULL)
    {
        return;
    }
    s = r->next;
    if (s == NULL)
    {
        return;
    }
    t = s->next;
    while (t)
    {
        s->next = r;
        r = s;
        s = t;
        t = t->next;
    }
    s->next = r;
    L->next->next = NULL;
    L->next = s;
}
int main()
{
    Linklist L, L1;
    tail_insert(L);
    tail_insert(L1);
    print_list(L);
    print_list(L1);
    cout << "---------------------" << endl;
    merge(L, L1);
    print_list(L);
    cout << "---------------------" << endl;
    reverse(L);
    print_list(L);
}