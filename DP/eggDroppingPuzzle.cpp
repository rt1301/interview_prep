#include <bits/stdc++.h>
using namespace std;

int solution(int f, int e)
{
    int dp[f + 1][e + 1]; // dp table
    // Fill out the base conditions
    // res(f,1) = f
    // res(1,e) = 1
    // res(0,e) = 0
    for (int i = 1; i <= e; i++)
    {
        dp[0][i] = 0; // no floors present
        dp[1][i] = 1; // only 1 floor is present
    }
    for (int i = 2; i <= f; i++)
    {
        dp[i][1] = i;
    }
    // Fill the dp array using the foll. recursive relation
    // res(f,e) = Min(1<=x<=f)(max(res(f-1,e-1),res(f-x,e)) + 1)
    for (int i = 2; i <= f; i++)
    {
        for (int j = 2; j <= e; j++)
        {
            dp[i][j] = INT_MAX;
            for (int x = 1; x <= i; x++)
            {
                dp[i][j] = min(dp[i][j], 1 + max(dp[x - 1][j - 1], dp[i - x][j]));
            }
        }
    }
    return dp[f][e];
}
// Recursion based solution
int solve(int e, int f)
{
    // Base Conditions
    if (f == 1 || f == 0)
    {
        return f;
    }
    if (e == 1)
        return f; //safely drop egg from 1st to fth floor

    int mn = INT_MAX;
    // Kth Loop
    // check 1st floor to fth Floor
    for (int k = 1; k <= f; k++)
    {
        // Worst case scenario
        // Case 1 - Egg Breaks -> e = e-1, f = k-1
        // Case 2 - Egg doesn't break -> e = e, f = f-k
        int temp = 1 + max(solve(e - 1, k - 1), solve(e, f - k));
        mn = min(mn, temp);
    }
    return mn;
}
// Memoized Soln
int dp[11][51];
int solveMemo(int e, int f)
{
    if (f == 0 || f == 1)
        return f;
    if (e == 1)
        return f;
    if (dp[e][f] != -1)
        return dp[e][f];
    int mn = INT_MAX;
    for (int k = 1; k <= f; k++)
    {
        int low=0,high=0;
        if(dp[e-1][k-1]!= -1){
            low = dp[e-1][k-1];
        }else{
            low = solve(e-1,k-1);
            dp[e-1][k-1] = low;
        }
        if(dp[e][f-k] != -1){
            high = dp[e][f-k];
        }else{
            high = solve(e,f-k);
            dp[e][f-k] = high;
        }
        int temp = 1 + max(low,high);
        mn = min(mn, temp);
    }
    return dp[e][f] = mn;
}
int main()
{
    int f = 5;
    int e = 3;
    memset(dp,-1,sizeof(dp));
    cout << solution(f, e);
    cout << "\nRecursive Soln " << solve(e, f);
    cout << "\nMemoized Solution " << solveMemo(e, f);
    return 0;
}