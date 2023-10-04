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

bool whether_continuous_subsequence(Linklist L1, Linklist L2)
{
    LNode *p1 = L1->next, *p2 = L2->next, *r = L1->next;
    while (p1 && p2)
    {
        if (p1->data != p2->data)
        {
            r = r->next;
            p1 = r;
            p2 = L2->next;
        }
        else
        {
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    if (p2)
        return false;
    else
        return true;
}
int main()
{
    Linklist L1, L2;
    tail_insert(L1);
    tail_insert(L2);
    print_list(L1);
    print_list(L2);
    cout << "---------------------" << endl;
    if (whether_continuous_subsequence(L1, L2))
        cout << "yes";
    else
        cout << "no";
    return 0;
}