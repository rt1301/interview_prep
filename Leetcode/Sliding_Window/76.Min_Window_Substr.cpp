#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string minWindow(string s, string t)
    {
        int n = s.length();
        unordered_map<char, int> mp;
        int i = 0, j = 0;
        for (int k = 0; k < t.length(); k++)
        {
            mp[t[k]]++;
        }
        int count = mp.size();
        if (mp.find(s[j]) != mp.end())
        {
            mp[s[j]]--;
            if (mp[s[j]] == 0)
                count--;
        }
        string ans = "";
        int minL = INT_MAX;
        int start = 0;
        while (j < n)
        {
            if (count > 0)
            {
                j++;
                if (mp.find(s[j]) != mp.end())
                {
                    mp[s[j]]--;
                    if (mp[s[j]] == 0)
                    {
                        count--;
                    }
                }
            }
            else if (count == 0)
            {
                if (minL > j - i + 1)
                {
                    minL = j - i + 1;
                    start = i;
                }
                while (count == 0)
                {
                    if (mp.find(s[i]) != mp.end())
                    {
                        mp[s[i]]++;
                        if (mp[s[i]] == 1)
                        {
                            if (minL > j - i + 1)
                            {
                                minL = j - i + 1;
                                start = i;
                            }
                            count++;
                        }
                        i++;
                    }
                    else
                    {
                        i++;
                    }
                }
            }
        }
        if (minL != INT_MAX)
        {
            return ans.append(s.substr(start, minL));
        }
        else
        {
            return ans;
        }
    }
};