#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int getSum(int n)
    {
        int ans = 0;
        while (n != 0)
        {
            ans += n % 10;
            n /= 10;
        }
        return ans;
    }
    int getLucky(string s, int k)
    {
        unordered_map<char, int> mp;
        char start = 'a';

        for (int i = 0; i < 26; i++)
        {
            mp[start] = i + 1;
            start++;
        }

        int ans = 0;
        for (int i = 0; i < s.length(); i++)
        {
            int it = mp[s[i]];
            ans += (getSum(it));
        }
        k--;
        while (k--)
        {
            ans = getSum(ans);
        }
        return ans;
    }
};