/****
 * The stock span problem is a financial problem where we have a series of n daily 
 * price quotes for a stock and we need to calculate the span of stock’s 
 * price for all n days. 
 * Problem Statement - https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1#
 ****/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector<int> ngl(int arr[], int n)
    {
        vector<int> v;
        stack<pair<int, int>> s;
        for (int i = 0; i < n; i++)
        {
            if (s.empty())
                v.push_back(-1);
            else if (!s.empty() && s.top().first > arr[i])
            {
                v.push_back(s.top().second);
            }
            else if (!s.empty() && s.top().first <= arr[i])
            {
                while (!s.empty() && s.top().first <= arr[i])
                {
                    s.pop();
                }
                if (s.empty())
                    v.push_back(-1);
                else
                    v.push_back(s.top().second);
            }
            s.push({arr[i], i});
        }
        return v;
    }
    vector<int> calculateSpan(int price[], int n)
    {
        vector<int> index = ngl(price, n);
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            ans[i] = i - index[i];
        }
        return ans;
    }
};