#include <bits/stdc++.h>
using namespace std;
vector<int> Solution::slidingMaximum(const vector<int> &A, int B)
{
    vector<int> ans;
    int n = A.size();
    if (B > n)
    {
        ans.push_back(*max_element(A.begin(), A.end()));
        return ans;
    }
    int i = 0, j = 0;
    vector<int> v;
    while (j < n)
    {
        while (v.size() > 0 && v[v.size() - 1] < A[j])
        {
            v.pop_back();
        }
        v.push_back(A[j]);
        if ((j - i + 1) < B)
            j++;
        else if ((j - i + 1) == B)
        {
            ans.push_back(*max_element(v.begin(), v.end()));
            if (v[0] == A[i])
            {
                v.erase(v.begin());
            }
            i++;
            j++;
        }
    }
    return ans;
}
