/****
 * Given a set of integers, the task is to divide it into two sets 
 * S1 and S2 such that the absolute difference between their sums is minimum. 
 * If there is a set S with n elements, then if we assume Subset1 has m elements, 
 * Subset2 must have n-m elements and the value of abs(sum(Subset1) – sum(Subset2)) 
 * should be minimum.
 ****/
#include <bits/stdc++.h>
using namespace std;
// Give the possible subset sum in 0 to totalSum of original array
vector<bool> subsetSum(int arr[], int n, int sum)
{
    // Dp table
    vector<vector<bool>> t(n + 1, vector<bool>(sum + 1));
    for (int i = 0; i <= sum; i++)
    {
        t[0][i] = 0;
    }
    for (int j = 0; j <= n; j++)
    {
        t[j][0] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i - 1] <= j)
            {
                t[i][j] = ((t[i - 1][j - arr[i - 1]]) || (t[i - 1][j]));
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n];
}
int subsetSumDiff(int arr[], int n)
{
    int totalSum = 0;
    for (int i = 0; i < n; i++)
    {
        totalSum += arr[i];
    }
    vector<bool> range = subsetSum(arr, n, totalSum);
    int s1 = 0; //first partition sum
    for (int i = (range.size()) / 2; i >= 0; i--)
    {
        if (range[i])
        {
            s1 = i;
            break;
        }
    }
    int s2 = totalSum - s1;
    return abs(s2 - s1);
}

int main()
{
    int arr[] = {3, 1, 4, 2, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The minimum difference between two sets is "
         << subsetSumDiff(arr, n);
    return 0;
}