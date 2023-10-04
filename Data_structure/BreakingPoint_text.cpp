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

int main()
{
    Linklist L;
    list_tail_insert(L);
    print_list(L);
}
