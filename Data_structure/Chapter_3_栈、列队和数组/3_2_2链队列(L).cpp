#include <bits/stdc++.h>
using namespace std;

typedef int DT;
typedef struct qnode
{
	DT data;
	struct qnode *next;
} LinkListQ;
typedef struct
{
	LinkListQ *f;
	LinkListQ *r;
} LinkQueue;

// 初始化
LinkQueue *InitQueue()
{
	LinkQueue *Q;
	LinkListQ *h;
	Q = (LinkQueue *)malloc(sizeof(LinkQueue));
	h = (LinkListQ *)malloc(sizeof(LinkListQ));
	Q->f = h;
	Q->r = h;
	return Q;
}

// 判空
int EmptyQueue(LinkQueue *Q)
{
	if (Q->f == Q->r)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

// 入队
void InQueue(LinkQueue *Q, DT x)
{
	LinkListQ *p;
	p = (LinkListQ *)malloc(sizeof(LinkListQ));
	p->data = x;
	p->next = NULL;
	Q->r->next = p;
	Q->r = p;
}

// 出队
int DeQueue(LinkQueue *Q, DT *x)
{
	LinkListQ *p;
	if (EmptyQueue(Q))
	{
		cout << "队空" << endl;
		return 0;
	}
	else
	{
		p = Q->f->next;
		*x = p->data;
		Q->f->next = p->next;
		if (p->next == NULL)
		{
			Q->r = Q->f;
		}
		free(p);
		return 1;
	}
}

void display(LinkQueue *Q)
{
	LinkListQ *p = Q->f;
	while (p->next != NULL)
	{
		cout << p->next->data << " ";
		p = p->next;
	}
	cout << endl;
}

int main()
{
	LinkQueue *Q = InitQueue();

	int n;
	cout << "请输入要入队元素的个数" << endl;
	cin >> n;
	cout << "请输入要入队的元素" << endl;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		InQueue(Q, x);
	}
	display(Q);

	cout << "请输入要出队元素的个数" << endl;
	cin >> n;
	cout << "以下元素已出队" << endl;
	for (int i = 0; i < n; i++)
	{
		int x;
		DeQueue(Q, &x);
		cout << x << " ";
	}
	cout << endl;
	cout << "出队后剩下的元素为：" << endl;
	display(Q);
}
