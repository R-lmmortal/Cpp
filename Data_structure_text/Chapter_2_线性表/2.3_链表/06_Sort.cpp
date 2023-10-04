#include <bits/stdc++.h>
using namespace std;

typedef int ElemType;
typedef struct LNone
{
    ElemType data;
    struct LNone *next;
} LNone, *Linklist;

void build_list(Linklist &L)
{
    L = (Linklist)malloc(sizeof(LNone));
    L->next = NULL;
    Linklist s, r = L;
    ElemType x;
    cin >> x;
    while (x != 9999)
    {
        s = (Linklist)malloc(sizeof(LNone));
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

void bubble_sort(Linklist &L)
{
    if (L->next == NULL || L->next->next == NULL)
    {
        return;
    }

    int swap;
    Linklist lastSort = NULL;
    Linklist p;

    do
    {
        swap = 0;
        p = L->next;
        while (p->next != lastSort)
        {
            if (p->data > p->next->data)
            {
                ElemType temp = p->data;
                p->data = p->next->data;
                p->next->data = temp;
                swap = 1;
            }
            p = p->next;
        }
        lastSort = p;
    } while (swap);
}

void insert_sort(Linklist &L)
{
    Linklist p = L->next, r = p->next, t;
    p->next = NULL;
    p = r;
    while (p)
    {
        r = p->next;
        t = L;
        while (t->next != NULL && t->next->data < p->data)
        {
            t = t->next;
        }
        p->next = t->next;
        t->next = p;
        p = r;
    }
}
int main()
{
    Linklist L;
    build_list(L);
    print_list(L);
    insert_sort(L);
    print_list(L);
    return 0;
}