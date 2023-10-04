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

void find_same_merge(Linklist &L, Linklist &L2)
{
    Linklist p = L->next, q = L2->next, r = L, s;
    while (p && q)
    {
        if (p->data < q->data)
        {
            s = p;
            p = p->next;
            free(s);
        }
        else if (p->data > q->data)
        {
            s = q;
            q = q->next;
            free(s);
        }
        else
        {
            r->next = p;
            r = p;
            p = p->next;
            s = q;
            q = q->next;
            free(s);
        }
    }
    while (p)
    {
        s = p;
        p = p->next;
        free(s);
    }
    while (q)
    {
        s = q;
        q = q->next;
        free(s);
    }
    r->next = NULL;
}

int main()
{
    Linklist L, L1;
    tail_insert(L);
    tail_insert(L1);
    print_list(L);
    print_list(L1);
    cout << "---------------------" << endl;
    cout << "find same" << endl;
    find_same_merge(L, L1);
    print_list(L);
    return 0;
}
