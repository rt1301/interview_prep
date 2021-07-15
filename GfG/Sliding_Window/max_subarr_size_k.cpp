/****
 * Given an array of integers Arr of size N and a number K. 
 * Return the maximum sum of a subarray of size K.
 * Problem Statement - https://practice.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1#
 ****/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maximumSumSubarray(int K, vector<int> &arr, int N)
    {
        // code here
        int sum = 0;
        int mx = INT_MIN;
        int i = 0, j = 0;
        while (j < N)
        {
            sum += arr[j];
            if ((j - i + 1) < K)
            {
                j++;
            }
            else if ((j - i + 1) == K)
            {
                mx = max(mx, sum);
                sum -= arr[i];
                i++;
                j++;
            }
        }
        return mx;
    }
};