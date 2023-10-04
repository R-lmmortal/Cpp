#include <bits/stdc++.h>
using namespace std;

typedef struct LNode
{
    char data;
    struct LNode *next;
} LNode, *Linklist;

char a[6] = {'a', 'b', 'c', 'c', 'b', 'a'};
int n = 6;
void tail_insert(Linklist &L)
{
    L = (Linklist)malloc(sizeof(LNode));
    L->next = NULL;
    LNode *s, *r = L;
    for (int i = 0; i < n; i++)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = a[i];
        r->next = s;
        r = s;
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

bool center(Linklist L, int n)
{
    char str[n / 2];
    LNode *p = L->next;
    int i;
    for (i = 0; i < n / 2; i++)
    {
        str[i] = p->data;
        p = p->next;
    }
    i--;
    if (n % 2 != 0)
        p = p->next;
    while (p && p->data == str[i])
    {
        i--;
        p = p->next;
    }
    if (i == -1)
        return true;
    return false;
}

int main()
{
    Linklist L;
    tail_insert(L);
    print_list(L);
    cout << "-------------------------------" << endl;
    if (center(L, n))
        cout << "yes" << endl;
    else
        cout << "no" << endl;
}