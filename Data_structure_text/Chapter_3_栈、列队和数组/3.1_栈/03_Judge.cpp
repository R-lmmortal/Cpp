#include <bits/stdc++.h>
using namespace std;

bool judge(char s[])
{
    int i = 0, I = 0, O = 0;
    while (s[i] != '\0')
    {
        switch (s[i])
        {
        case 'I':
            I++;
            break;
        case 'O':
        {
            O++;
            if (O > I)
            {
                cout << "非法序列" << endl;
                return false;
            }
        }
        }
        i++;
    }
    if (I != O)
    {
        cout << "非法序列" << endl;
        return false;
    }
    else
    {
        cout << "合法序列" << endl;
        return true;
    }
}
int main()
{
    char s[8] = {
        'I',
        'O',
        'I',
        'I',
        'O',
        'I',
        'O',
        'I',
    };
    judge(s);
    return 0;
}