#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> ans;
        int count = 0;
        unordered_map<char, int> mp;
        for (int i = 0; i < p.length(); i++)
        {
            if (mp[p[i]])
            {
                mp[p[i]]++;
            }
            else
            {
                mp[p[i]] = 1;
            }
        }
        int i = 0, j = 0;
        int n = s.length();
        int k = p.length();
        count = mp.size();
        while (j < n)
        {
            if (mp.find(s[j]) != mp.end())
            {
                mp[s[j]]--;
                if (mp[s[j]] == 0)
                {
                    count--;
                }
            }
            if ((j - i + 1) < k)
                j++;
            else if ((j - i + 1) == k)
            {
                if (count == 0)
                {
                    ans.push_back(i);
                }
                if (mp.find(s[i]) != mp.end())
                {
                    mp[s[i]]++;
                    if (mp[s[i]] == 1)
                    {
                        count++;
                    }
                }
                i++;
                j++;
            }
        }

        return ans;
    }
};