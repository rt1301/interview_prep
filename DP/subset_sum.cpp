/****
 * Given a set of non-negative integers, and a value sum, 
 * determine if there is a subset of the given set with sum equal to given sum. 
 ****/
#include <bits/stdc++.h>
using namespace std;

bool isSum(int arr[], int n, int sum)
{
    // Create a dp table
    bool t[n + 1][sum + 1];
    // initialize base conditions
    // when sum = 0, empty set is possible
    for (int i = 0; i <= n; i++)
    {
        t[i][0] = 1;
    }
    // when arr is null, no subset is possible
    for (int j = 1; j <= sum; j++)
    {
        t[0][j] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            // check if number in arr is less than reqd sum
            if (arr[i - 1] <= j)
            {
                // 2 cases - either take num in subset or don't
                t[i][j] = ((t[i - 1][j - arr[i - 1]]) || (t[i - 1][j]));
            }
            else
            {
                // don't take number in subset coz its bigger than reqd sum
                t[i][j] = t[i - 1][j];
            }
        }
    }

    return t[n][sum];
}
int main()
{
    int set[] = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    int n = sizeof(set) / sizeof(set[0]);
    if (isSum(set, n, sum))
    {
        cout << "Subset is possible";
    }
    else
    {
        cout << "Subset is not possible";
    }
    return 0;
}