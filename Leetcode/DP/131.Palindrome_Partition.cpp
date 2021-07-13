#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<string>> res;
    vector<string> curr;
    bool dp[17][17];
    bool isPalindrome(string s, int i, int j)
    {
        while (i < j)
        {
            if (s[i] != s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void solve(string s, int i)
    {
        int n = s.length();
        if (i >= n)
        {
            res.push_back(curr);
            return;
        }
        for (int k = i; k < n; k++)
        {
            if (s[i] == s[k] && (k - i <= 2 || dp[i + 1][k - 1]))
            {
                dp[i][k] = true;
                curr.push_back(s.substr(i, k - i + 1));
                solve(s, k + 1);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        int i = 0;
        int j = s.length() - 1;
        memset(dp, 0, sizeof(dp));
        solve(s, i);
        return res;
    }
};