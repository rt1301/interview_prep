#include <bits/stdc++.h>
using namespace std;
vector<int> Solution::findPerm(const string A, int B)
{
    vector<int> ans;
    int n = B;
    int l = 1;
    for (int i = 0; i < A.length(); i++)
    {
        if (A[i] == 'I')
        {
            ans.push_back(l);
            l++;
        }
        else
        {
            ans.push_back(n);
            n--;
        }
    }
    if (A.back() == 'I')
    {
        ans.push_back(n);
    }
    else
    {
        ans.push_back(l);
    }
    return ans;
}
