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
        s->next = r->next;
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

void swap(Linklist &L, int a, int b)
{
    int j = 0;
    Linklist r = NULL, s = NULL;
    for (Linklist p = L->next; p != NULL; p = p->next)
    {
        j++;
        if (a == j)
        {
            r = p;
        }
        if (b == j)
        {
            s = p;
        }
    }
    if (r == NULL || s == NULL)
    {
        cout << "Invalid positions for swapping." << endl;
        return;
    }
    ElemType temp = r->data;
    r->data = s->data;
    s->data = temp;
}
int main()
{
    Linklist L;
    build_list(L);
    print_list(L);
    return 0;
}