#include <bits/stdc++.h>
using namespace std;
int main()
{
	int st[100];
	int top = -1;
	int n;
	cin >> n;
	while (n)
	{
		st[++top] = n % 2;
		n /= 2;
	}
	while (top != -1)
	{
		cout << st[top--];
	}
	return 0;
}
