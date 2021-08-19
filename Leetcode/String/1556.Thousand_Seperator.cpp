#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string thousandSeparator(int n)
    {
        if (n == 0)
        {
            return "0";
        }
        string ans = "";
        int count = 0;
        while (n > 0)
        {
            if (count == 3)
            {
                ans.push_back('.');
                count = 0;
            }
            int rem = n % 10;
            ans += (to_string(rem));
            count++;
            n /= 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};