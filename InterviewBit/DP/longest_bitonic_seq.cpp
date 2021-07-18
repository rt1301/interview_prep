#include <bits/stdc++.h>
using namespace std;
int longestSubsequenceLength(const vector<int> &arr)
{
    int n = arr.size();
    if (n == 0)
        return 0;
    int lis[n];
    int lds[n];
    for (int i = 0; i < n; i++)
    {
        lis[i] = 1;
        lds[i] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && lis[i] < (lis[j] + 1))
            {
                lis[i] = lis[j] + 1;
            }
        }
    }
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (arr[i] > arr[j] && lds[i] < (lds[j] + 1))
            {
                lds[i] = lds[j] + 1;
            }
        }
    }
    int maxAns = lis[0] + lds[0] - 1;
    for (int i = 1; i < n; i++)
    {
        maxAns = max(maxAns, lis[i] + lds[i] - 1);
    }
    return maxAns;
}