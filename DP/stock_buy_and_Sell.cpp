/****
 * The cost of stock on each day is given in an array A[] of size N. 
 * Find all the days on which you buy and sell the stock so that in between those 
 * days your profit is maximum.
 * PS - https://practice.geeksforgeeks.org/problems/stock-buy-and-sell-1587115621/1
 ****/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    //Function to find the days of buying and selling stock for max profit.
    vector<vector<int>> stockBuySell(vector<int> arr, int n)
    {
        // code here
        vector<vector<int>> ans;
        int i = 0;
        int peak = 0;
        int valley = 0;
        while (i < n - 1)
        {
            while (i < n - 1 && arr[i] >= arr[i + 1])
            {
                i++;
            }
            valley = i;
            while (i < n - 1 && arr[i] <= arr[i + 1])
            {
                i++;
            }
            peak = i;
            if (peak != valley)
            {
                ans.push_back({valley, peak});
            }
        }
        return ans;
    }
};