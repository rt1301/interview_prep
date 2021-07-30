#include <bits/stdc++.h>
using namespace std;
vector<int> Solution::solve(vector<int> &A)
{
    vector<int> ans;
    int mx = INT_MIN;
    int curr = 0;
    for (int i = A.size() - 1; i >= 0; i--)
    {
        curr = A[i];
        if (mx < curr)
        {
            mx = curr;
            ans.push_back(A[i]);
        }
    }
    return ans;
}
