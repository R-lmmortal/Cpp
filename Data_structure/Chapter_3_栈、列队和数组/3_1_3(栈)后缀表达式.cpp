#include <bits/stdc++.h>
using namespace std;

int main()
{
	int st[100];
	int top = -1;
	int a, b, c;
	string st;
	cin >> st;
	for (int i = 0; st[i] != '@'; i++)
	{ //'@'表示最后一个字符
		if (st[i] == '+')
		{
			a = st[top--];
			b = st[top--];
			st[++top] = b + a; // 计算结果入栈
		}
		else if (st[i] == '-')
		{
			a = st[top--];
			b = st[top--];
			st[++top] = b - a;
		}
		else if (st[i] == '*')
		{
			a = st[top--];
			b = st[top--];
			st[++top] = b * a;
		}
		else if (st[i] == '.')
		{
			st[++top] = c;
			c = 0;
		}
		else
		{ // 读到数字字符
			c = c * 10 + st[i] - '0';
		}
	}
	cout << st[top];
}
