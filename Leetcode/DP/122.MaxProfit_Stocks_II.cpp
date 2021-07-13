#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int i = 0;
        int maxProfit = 0;
        int peak = 0;
        int valley = 0;
        while (i < n - 1)
        {
            while (i < n - 1 && prices[i] >= prices[i + 1])
            {
                i++;
            }
            valley = prices[i];
            while (i < n - 1 && prices[i] <= prices[i + 1])
            {
                i++;
            }
            peak = prices[i];
            maxProfit += (peak - valley);
        }
        return maxProfit;
    }
    // Greedy Soln
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int maxProfit = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (prices[i + 1] > prices[i])
            {
                maxProfit += (prices[i + 1] - prices[i]);
            }
        }
        return maxProfit;
    }
};