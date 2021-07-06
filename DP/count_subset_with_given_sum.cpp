/****
 * Given an array arr[] of length N and an integer X, 
 * the task is to find the number of subsets with a sum equal to X.
 * Very similar to Subset Sum Problem
 ****/
#include <bits/stdc++.h>
using namespace std;

int countSubsets(int arr[], int n, int sum)
{
    int t[n + 1][sum + 1];
    for (int j = 0; j <= sum; j++)
    {
        t[0][j] = 0;
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
                // Adding the two cases because we need to check for all the
                // different subsets combination
                t[i][j] = ((t[i - 1][j - arr[i - 1]]) + (t[i - 1][j]));
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][sum];
}

int main()
{
    int arr[] = {3, 3, 3, 3};
    int n = sizeof(arr) / sizeof(int);
    int x = 6;
    cout << countSubsets(arr, n, x);
    return 0;
}