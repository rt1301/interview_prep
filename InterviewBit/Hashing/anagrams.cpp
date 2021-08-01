#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> Solution::anagrams(const vector<string> &A)
{
    vector<vector<int>> ans;
    int n = A.size();
    unordered_map<string, vector<int>> mp;
    for (int i = 0; i < n; i++)
    {
        string temp = A[i];
        sort(temp.begin(), temp.end());
        mp[temp].push_back(i + 1);
    }
    for (const auto &it : mp)
        ans.push_back(move(it.second));
    return ans;
}
