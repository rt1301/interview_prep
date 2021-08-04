#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxDistToClosest(vector<int> &seats)
    {
        int ans = INT_MIN;
        int n = seats.size();
        vector<int> left;
        vector<int> right(n);
        int one = -1;
        for (int i = 0; i < n; i++)
        {
            if (seats[i])
            {
                one = i;
                left.push_back(-1);
            }
            else
            {
                int d;
                if (one != -1)
                {
                    d = abs(i - one);
                }
                else
                {
                    d = INT_MAX - 1;
                }
                left.push_back(d);
            }
        }
        one = -1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (seats[i])
            {
                one = i;
                right[i] = (-1);
            }
            else
            {
                int d;
                if (one != -1)
                {
                    d = abs(i - one);
                }
                else
                {
                    d = INT_MAX - 1;
                }
                right[i] = (d);
            }
        }
        for (int i = 0; i < left.size(); i++)
        {
            int d = min(left[i], right[i]);
            ans = max(ans, d);
        }
        return ans;
    }
};