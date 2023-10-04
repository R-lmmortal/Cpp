#include <bits/stdc++.h>
using namespace std;

#define MAX 100

typedef struct
{
    char data[MAX + 1];
    int top;
} Stack;

bool isEmpty(Stack s)
{
    if (s.top == -1)
        return true;
    return false;
}

bool isFull(Stack s)
{
    if (s.top == MAX - 1)
        return true;
    return false;
}

bool enterstack(Stack &s, char x)
{
    if (isFull(s))
    {
        cout << "栈满" << endl;
        return false;
    }
    s.data[++s.top] = x;
    return true;
}

int outstack(Stack &s, char &x)
{
    if (isEmpty(s))
    {
        cout << "栈空" << endl;
        return 0;
    }
    x = s.data[s.top--];
    return 1;
}

bool match(char *str)
{
    Stack s;
    s.top = -1;
    int i = 0;
    char x;
    while (str[i] != '\0')
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
            enterstack(s, str[i]);
        else if (str[i] == ')')
        {
            outstack(s, x);
            if (x != '(')
                return false;
        }
        else if (str[i] == ']')
        {
            outstack(s, x);
            if (x != '[')
                return false;
        }
        else if (str[i] == '}')
        {
            outstack(s, x);
            if (x != '{')
                return false;
        }
        i++;
    }
    if (isEmpty(s))
        return true;
    return false;
}
int main()
{
    char *str = (char *)"()[]{}(";
    cout << str << endl;
    if (match(str))
        cout << "括号匹配" << endl;
    else
        cout << "括号不匹配" << endl;
    return 0;
}