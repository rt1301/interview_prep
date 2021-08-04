/****
 * Given an array of positive numbers, the task is to find the number of 
 * possible contiguous subarrays having product less than a given number k.
 ****/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countSubArrayProductLessThanK(const vector<int> &a, int n, long long k)
    {
        long long mult = 1;
        int count = 0;
        int i = 0, j = 0;
        while (j < n)
        {
            mult *= a[j];
            if (mult >= k)
            {
                while (i < j && mult >= k)
                {
                    mult /= a[i];
                    i++;
                }
            }
            if (mult < k)
            {
                count += (j - i + 1);
            }
            j++;
        }
        return count;
    }
};