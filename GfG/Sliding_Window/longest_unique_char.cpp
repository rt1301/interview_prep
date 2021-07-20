/****
 * Given a string you need to print the size of the longest 
 * possible substring that has exactly K unique characters. 
 * If there is no possible substring then print -1.
 * Problem St - https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853
 ****/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int longestKSubstr(string s, int k)
    {
        // your code here
        int i = 0;
        int j = 0;
        unordered_map<char, int> mp;
        int mx = INT_MIN;
        while (j < s.length())
        {
            mp[s[j]]++;
            if (mp.size() < k)
                j++;
            else if (mp.size() == k)
            {
                mx = max(mx, j - i + 1);
                j++;
            }
            else if (mp.size() > k)
            {
                while (mp.size() > k)
                {
                    mp[s[i]]--;
                    if (mp[s[i]] == 0)
                    {
                        mp.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        if (mx == INT_MIN)
        {
            return -1;
        }
        return mx;
    }
};