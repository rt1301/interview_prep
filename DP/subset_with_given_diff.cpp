/****
 * Given an array of integers and a difference
 * Find the number of subsets whose difference of sums
 * equals the given difference
 ****/
#include <bits/stdc++.h>
using namespace std;
int countSubsets(int arr[], int n, int sum)
{
    int t[n + 1][sum + 1];
    for (int i = 0; i <= sum; i++)
    {
        t[0][i] = 0;
    }
    for (int i = 0; i <= n; i++)
    {
        t[i][0] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i - 1] <= j)
            {
                t[i][j] = t[i - 1][j - arr[i - 1]] + t[i - 1][j];
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    return t[n][sum];
}
int subsetDiff(int arr[], int n, int diff)
{
    int totalSum = 0;
    for (int i = 0; i < n; i++)
    {
        totalSum += arr[i];
    }
    if ((totalSum + diff) % 2 != 0)
    {
        // total sum + diff is odd
        return 0;
    }

    int s = (totalSum + diff) / 2;
    int ans = countSubsets(arr, n, s);

    return ans;
}

int main()
{
    int ans[] = {1, 1, 2, 3};
    int n = sizeof(ans) / sizeof(ans[0]);
    int diff = 1;
    cout << subsetDiff(ans, n, diff);
    return 0;
}