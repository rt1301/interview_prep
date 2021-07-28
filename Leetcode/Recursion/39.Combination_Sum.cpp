#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> ans;
    void helper(vector<int> &ca, int n, int target, vector<int> &ds)
    {
        if (n == 0)
        {
            if (target == 0)
            {
                ans.push_back(ds);
            }
            return;
        }
        if (ca[n - 1] <= target)
        {
            ds.push_back(ca[n - 1]);
            helper(ca, n, target - ca[n - 1], ds);
            ds.pop_back();
        }

        helper(ca, n - 1, target, ds);
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> ds;
        helper(candidates, candidates.size(), target, ds);
        return ans;
    }
};