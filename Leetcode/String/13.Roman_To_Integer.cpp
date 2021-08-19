#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int romanToInt(string s)
    {
        unordered_map<char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        int ans = mp[s[0]];
        int last = mp[s[0]];
        for (int i = 1; i < s.length(); i++)
        {
            int curr = mp[s[i]];
            if (curr > last)
            {
                ans += (curr - 2 * last);
            }
            else
            {
                ans = (curr + ans);
            }
            last = curr;
        }
        return ans;
    }
};