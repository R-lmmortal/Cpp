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

void three_pointer_reverse(Linklist &L)
{
    Linklist r, s, t;
    r = L->next;
    if (r == NULL)
        return;
    s = r->next;
    if (s == NULL)
        return;
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
    Linklist L;
    list_tail_insert(L);
    print_list(L);
    cout << "---------------------" << endl;
    reverse(L);
    print_list(L);
    cout << "---------------------" << endl;
    three_pointer_reverse(L);
    print_list(L);
    return 0;
}