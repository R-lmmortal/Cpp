#include <bits/stdc++.h>
using namespace std;

struct Tree
{
    int data[12] = {-1, 1, 2, 3, -1, 4, -1, 5, -1, -1, 6, -1};
};

int recent_public_ancestor(Tree t, int i, int j)
{
    if (t.data[i] != -1 && t.data[j] != -1)
    {
        while (i != j)
        {
            if (i > j)
                i /= 2;
            else
                j /= 2;
        }
        return t.data[i];
    }
}

int main()
{
    Tree t;
    int ans = recent_public_ancestor(t, 7, 10);
    cout << ans << endl;
    return 0;
}