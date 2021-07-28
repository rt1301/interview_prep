/****
 * Find the largest rectangular area possible in a given histogram where 
 * the largest rectangle can be made of a number of contiguous bars. 
 * For simplicity, assume that all bars have the same width and the width is 1 unit.
 * Problem Statement - https://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1#
 ****/
#include <bits/stdc++.h>
using namespace std;
// Variation of Next Smaller Left Element + Next Smaller Right Element
class Solution
{
public:
    //Function to find largest rectangular area possible in a given histogram.
    vector<int> nsl(long long arr[], int n)
    {
        vector<int> v;
        stack<pair<long long, int>> s;
        for (int i = 0; i < n; i++)
        {
            if (s.empty())
            {
                v.push_back(-1);
            }
            else if (!s.empty() && s.top().first < arr[i])
            {
                v.push_back(s.top().second);
            }
            else if (!s.empty() && s.top().first >= arr[i])
            {
                while (!s.empty() && s.top().first >= arr[i])
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
    vector<int> nsr(long long arr[], int n)
    {
        vector<int> v;
        stack<pair<long long, int>> s;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s.empty())
            {
                v.push_back(n);
            }
            else if (!s.empty() && s.top().first < arr[i])
            {
                v.push_back(s.top().second);
            }
            else if (!s.empty() && s.top().first >= arr[i])
            {
                while (!s.empty() && s.top().first >= arr[i])
                {
                    s.pop();
                }
                if (s.empty())
                    v.push_back(n);
                else
                    v.push_back(s.top().second);
            }
            s.push({arr[i], i});
        }
        reverse(v.begin(), v.end());
        return v;
    }
    long long getMaxArea(long long arr[], int n)
    {
        vector<int> id1 = nsl(arr, n);
        vector<int> id2 = nsr(arr, n);
        long long ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            long long temp = arr[i] * ((id2[i] - id1[i]) - 1);
            ans = max(ans, temp);
        }
        return ans;
    }
};