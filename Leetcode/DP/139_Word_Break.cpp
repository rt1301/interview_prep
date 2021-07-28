#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    unordered_set<string> st;
    int dp[305];
    bool dictFind(string s)
    {
        if (st.find(s) != st.end())
            return true;
        return false;
    }
    bool solve(string s)
    {
        int n = s.length();
        if (n == 0)
            return true;
        if (dp[n] != -1)
            return dp[n];
        for (int i = 1; i <= n; i++)
        {
            bool temp = dictFind(s.substr(0, i)) && solve(s.substr(i, n - 1));
            if (temp)
                return dp[i] = temp;
        }
        return dp[n] = 0;
    }
    bool wordBreak(string s, vector<string> &wordDict)
    {
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < wordDict.size(); i++)
        {
            st.insert(wordDict[i]);
        }
        return solve(s);
    }
};