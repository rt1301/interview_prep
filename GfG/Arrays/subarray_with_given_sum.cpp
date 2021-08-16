/****
 * Given an unsorted array of nonnegative integers, find a continuous 
 * subarray which adds to a given number. 
 ****/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, int s)
    {
        // Your code here
        int i = 0, j = 0;
        vector<int> ans;
        int sum = 0;
        while (j < n)
        {
            sum += arr[j];
            if (sum < s)
            {
                j++;
            }
            else if (sum == s)
            {
                ans.push_back(i + 1);
                ans.push_back(j + 1);
                return ans;
            }
            else if (sum > s)
            {
                while (sum > s)
                {
                    sum -= arr[i];
                    i++;
                }
                if (sum == s)
                {
                    ans.push_back(i + 1);
                    ans.push_back(j + 1);
                    return ans;
                }
                j++;
            }
        }
        if (ans.empty())
        {
            return {-1};
        }
        return ans;
    }
};
