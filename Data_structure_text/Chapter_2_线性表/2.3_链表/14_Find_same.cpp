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

void find_same1(Linklist L, Linklist L1, Linklist &L2)
{
    L2 = (Linklist)malloc(sizeof(LNode));
    L2->next = NULL;
    Linklist p = L->next, q = L1->next, r = L2, s;
    while (p && q)
    {
        if (p->data < q->data)
            p = p->next;
        else if (p->data > q->data)
            q = q->next;
        else
        {
            s = (Linklist)malloc(sizeof(LNode));
            s->data = p->data;
            s->next = r->next;
            r->next = s;
            r = s;
            p = p->next;
            q = q->next;
        }
    }
}

void find_same(Linklist L, Linklist L1, Linklist &L2)
{
    L2 = (Linklist)malloc(sizeof(LNode));
    L2->next = NULL;
    Linklist p = L->next, q = L1->next, r = L2, s;
    while (q)
    {
        while (p)
        {
            if (p->data != q->data)
            {
                p = p->next;
            }
            else
            {
                bool alreadyInserted = false;
                Linklist temp = L2->next;
                while (temp)
                {
                    if (temp->data == q->data)
                    {
                        alreadyInserted = true; // 检查是否已经插入过相同元素
                        break;
                    }
                    temp = temp->next;
                }
                if (!alreadyInserted)
                {
                    s = (Linklist)malloc(sizeof(LNode));
                    s->data = p->data;
                    s->next = r->next;
                    r->next = s;
                    r = s;
                }
                p = p->next;
            }
        }
        q = q->next;
        p = L->next;
    }
}

int main()
{
    Linklist L, L1, L2;
    tail_insert(L);
    tail_insert(L1);
    print_list(L);
    print_list(L1);
    cout << "---------------------" << endl;
    cout << "find same" << endl;
    find_same1(L, L1, L2);
    print_list(L2);
    return 0;
}
