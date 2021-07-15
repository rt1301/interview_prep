#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numSplits(string s)
    {
        int n = s.length();
        int dp[n];
        set<char> t;
        for (int i = 0; i < n; i++)
        {
            t.insert(s[i]);
            dp[i] = t.size();
        }
        int ans = 0;
        t.clear();
        for (int i = n - 1; i > 0; i--)
        {
            t.insert(s[i]);
            if (t.size() == dp[i - 1])
                ans++;
        }
        return ans;
    }
};

// Brute Force Solution
bool isGood(string s1, string s2)
{
    set<char> set1;
    set<char> set2;
    for (int i = 0; i < s1.length(); i++)
    {
        set1.insert(s1[i]);
    }
    for (int i = 0; i < s2.length(); i++)
    {
        set2.insert(s2[i]);
    }
    return set1.size() == set2.size();
}
int numSplits(string s)
{
    // mp.clear();
    int i = 0;
    int j = s.length() - 1;
    int ans = 0;
    for (int k = i; k <= j; k++)
    {
        string s1 = s.substr(0, k);
        string s2 = s.substr(k, j);
        if (isGood(s1, s2))
        {
            ans++;
        }
    }
    return ans;
}