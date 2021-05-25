#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> corpFlightBookings(vector<vector<int>> &b, int n)
    {
        vector<int> a(n, 0);
        for (int i = 0; i < b.size(); i++)
        {
            int first = b[i][0] - 1;
            int last = b[i][1];
            a[first] += b[i][2];
            if (last < n)
            {
                a[last] -= b[i][2];
            }
        }
        for (int i = 1; i < a.size(); i++)
        {
            a[i] += a[i - 1];
        }
        return a;
    }
};