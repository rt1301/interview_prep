#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> ans(n + 1, 0);
        if (n >= 1)
            ans[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            ans[i] = ans[i / 2] + (i % 2 == 0 ? 0 : 1);
        }
        return ans;
    }
    // Alternative Soln
    int getBits(int n)
    {
        int count = 0;
        if (n >= 2 && (n & (n - 1)) == 0)
            return 1;
        while (n != 0)
        {
            n = (n & (n - 1));
            count++;
        }
        return count;
    }
    vector<int> countBits(int n)
    {
        vector<int> ans;
        for (int i = 0; i <= n; i++)
        {
            ans.push_back(getBits(i));
        }
        return ans;
    }
};