#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        bool flag = true;
        for (int i = t.length() - 1; i >= 0; i--)
        {
            if (!s.empty())
            {
                if (t[i] == s[s.length() - 1])
                {
                    flag = true;
                    s.pop_back();
                }
                else
                {
                    flag = false;
                }
            }
            else
            {
                flag = true;
                break;
            }
        }
        if (flag && s.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};