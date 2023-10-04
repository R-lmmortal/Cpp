// 已知一颗满二叉树的先序序列，设计一个算法求其后续序列
#include <bits/stdc++.h>
using namespace std;

void PerToPost(char pre[], int l1, int h1, char post[], int l2, int h2)
{
    int half;
    if (l1 < h1)
    {
        post[h2] = pre[l1];
        half = (h1 - l1) / 2;
        PerToPost(pre, l1 + 1, l1 + half, post, l2, l2 + half - 1);
        PerToPost(pre, l1 + half + 1, h1, post, l2 + half, h2 - 1);
    }
}
int main()
{
    char pre[8] = "ABDECFG", post[8];
    PerToPost(pre, 0, 6, post, 0, 6);
    for (int i = 0; i < 7; i++)
    {
        cout << post[i] << " ";
    }
    return 0;
}
/*       A
       /   \
      B     C
     / \   / \
    D   E F   G
  ABD##E##CF##G##
      ABDECFG
      DEBFGCA
*/