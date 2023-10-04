#include <bits/stdc++.h>
using namespace std;

#define MAXLEN 100
typedef int DataType;
typedef struct
{
	DataType data[MAXLEN];
	int top;
} SeqStack;

// 初始化
void InitStack(SeqStack *s)
{
	s->top = -1;
}

// 判断是否为空栈
int EmptyStack(SeqStack *s)
{
	if (s->top == -1)
		return 1;
	else
		return 0;
}

// 判断是否满栈
int FullStack(SeqStack *s)
{
	if (s->top == MAXLEN - 1)
		return 1;
	else
		return 0;
}

// 进栈
int Push(SeqStack *s, DataType x)
{
	if (FullStack(s))
	{
		cout << "栈满，不能进栈！" << endl;
		return 0;
	}
	else
	{
		s->top++;
		s->data[s->top] = x;
		return 1;
	}
}

// 出栈
int Pop(SeqStack *s, DataType *x)
{
	if (!EmptyStack(s))
	{
		*x = s->data[s->top];
		s->top--;
		return 1;
	}
	else
	{
		cout << "栈空，不能出栈！" << endl;
		return 0;
	}
}

// 取栈顶元素
int GetTop(SeqStack *s, DataType *x)
{
	if (!EmptyStack(s))
	{
		*x = s->data[s->top];
		return 1;
	}
	else
	{
		cout << "栈空，取顶元素失败！" << endl;
		return 0;
	}
}

void D_B(int n)
{
	int r;			// 变量存放余数
	SeqStack st;	// 创建栈
	InitStack(&st); // 初始化栈
	while (n)
	{
		r = n % 2;
		Push(&st, r); // 余数入栈
		n /= 2;
	}
	// 将栈中元素出栈，并输出
	while (!EmptyStack(&st))
	{
		Pop(&st, &r);
		cout << r << " ";
	}
	cout << "\n"
		 << endl;
}
int main()
{
	int n;
	cin >> n;
	D_B(n);
}
