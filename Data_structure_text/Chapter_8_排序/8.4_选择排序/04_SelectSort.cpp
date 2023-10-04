// 编写一个算法，在基于单链表表示的待排序序列上进行简单选择排序
#include <bits/stdc++.h>
using namespace std;

typedef struct LNone
{
    int data;
    struct LNone *next;
} LNone, *Linklist;

int a[10] = {7, 5, 9, 2, 6, 4, 3, 8, 1};
int n = 9;

void buildlist(LNone *L)
{
    Linklist s, r = L;
    r->data = a[0];
    if (n == 1)
        r->next = NULL;
    else
    {
        for (int i = 1; i < n; i++)
        {
            s = (LNone *)malloc(sizeof(LNone));
            s->data = a[i];
            r->next = s;
            r = r->next;
        }
        r->next = NULL;
    }
}

void print_list(Linklist L)
{
    Linklist s = L;
    while (s)
    {
        cout << s->data << " ";
        s = s->next;
    }
    cout << endl;
}

void SelectSort(Linklist &l)
{
    Linklist h = l, p, q, s, r;
    l = NULL;
    while (h != NULL)
    {
        s = p = h;
        q = r = NULL;
        while (p != NULL)
        {
            if (p->data > s->data)
            {
                s = p;
                r = q;
            }
            q = p;
            p = p->next;
        }
        if (s == h)
            h = h->next;
        else
        {
            r->next = s->next;
        }
        s->next = l;
        l = s;
    }
}

int main()
{
    LNone L;
    LNone *l = &L;
    buildlist(l);
    print_list(l);
    cout << "---------------------" << endl;
    SelectSort(l);
    print_list(l);
    return 0;
}