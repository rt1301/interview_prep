/****
 * Partition problem is to determine whether a given set can be partitioned into 
 * two subsets such that the sum of elements in both subsets is the same. 
 * Similar to Subset Sum problem
 ****/

/****
 * Two subsets whose sum is equal
 * can only occur if total sum of arr is even
 * We need to only fine one subset with sum = totalSum/2;
 * Coz the other subset will have the rem equal sum
 ****/
#include <bits/stdc++.h>
using namespace std;
bool equalPart(int arr[], int n)
{
    int totalSum = 0;
    for (int i = 0; i < n; i++)
    {
        totalSum += arr[i];
    }
    if (totalSum % 2 != 0)
    {
        return false;
    }
    int sum = totalSum / 2;
    // Dp table
    bool t[n + 1][sum + 1];
    for (int i = 0; i <= n; i++)
    {
        t[i][0] = 1;
    }
    for (int j = 1; j <= sum; j++)
    {
        t[0][j] = 0;
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

    return t[n][sum];
}
int main()
{
    int arr[] = {3, 1, 5, 9, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Function call
    if (equalPart(arr, n) == true)
        cout << "Can be divided into two subsets "
                "of equal sum";
    else
        cout << "Can not be divided into two subsets"
                " of equal sum";
    return 0;
    return 0;
}