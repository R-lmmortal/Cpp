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
int Push(SeqStack *s, char x)
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
int Pop(SeqStack *s, char *x)
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
int GetTop(SeqStack *s, char *x)
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

bool bracketCheck(char str[], int len)
{
    SeqStack s;
    InitStack(&s);

    for (int i = 0; i < len; i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            Push(&s, str[i]);
        }
        else
        {
            if (EmptyStack(&s))
            {
                return 0;
            }
            char topElem;
            Pop(&s, &topElem);
            if (str[i] == ')' && topElem != '(')
            {
                cout << "匹配失败";
                return false;
            }

            if (str[i] == ']' && topElem != '[')
            {
                cout << "匹配失败";
                return false;
            }
            if (str[i] == '}' && topElem != '{')
            {
                cout << "匹配失败";
                return false;
            }
        }
    }
    if (EmptyStack(&s))
    {
        cout << "匹配成功";
        return 1;
    }
    else
    {
        cout << "匹配失败";
        return 0;
    }
}

int GetLength(char str[])
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

int main()
{
    char str[100];
    cout << "请输入括号：";
    cin >> str;
    int len = GetLength(str);
    bracketCheck(str, len);
}