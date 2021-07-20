#include <bits/stdc++.h>
using namespace std;
class Solution
{

public:
    int lengthOfLongestSubstring(string s)
    {
        int i = 0;
        int j = 0;
        unordered_map<char, int> mp;
        int mx = 0;
        int k = 0;
        while (j < s.length())
        {
            k = j - i + 1;
            mp[s[j]]++;
            if (mp.size() == k)
            {
                mx = max(mx, j - i + 1);
            }
            else if (mp.size() < k)
            {
                while (mp.size() < k)
                {
                    mp[s[i]]--;
                    if (mp[s[i]] == 0)
                    {
                        mp.erase(s[i]);
                    }
                    i++;
                    k--;
                }
                if (mp.size() == k)
                {
                    mx = max(mx, k);
                }
            }
            j++;
        }
        return mx;
    }
};