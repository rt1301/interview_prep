#include<bits/stdc++.h>
using namespace std;
vector<int> prefix(string s)
{
    int n = s.length();
    vector<int> pi(n, 0);
    for (int i = 1; i < n; i++)
    {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
        {
            j = pi[j - 1];
        }
        if (s[i] == s[j])
        {
            j++;
        }
        pi[i] = j;
    }
    return pi;
}
int Solution::strStr(const string A, const string B)
{
    int m = A.length();
    int n = B.length();
    if (n == 0 || (m == 0 && n == 0))
    {
        return -1;
    }
    vector<int> pi = prefix(B);
    int i = 0, j = 0;
    int pos = -1;
    while (i < m)
    {
        if (A[i] == B[j])
        {
            i++;
            j++;
        }
        else
        {
            if (j != 0)
            {
                j = pi[j - 1];
            }
            else
            {
                i++;
            }
        }
        if (j == n)
        {
            pos = i - n;
            break;
        }
    }
    return pos;
}