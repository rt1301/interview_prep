/****
 * Given two strings of length m and n respectively.
 * Find the length of the longest common subsequence of the strings
 ****/
#include <bits/stdc++.h>
using namespace std;

int lcs(int dp[100][100], string x, string y, int n, int m)
{
    if (dp[n][m] != -1)
    {
        return dp[n][m];
    }
    if (n == 0 || m == 0)
    {
        return dp[n][m] = 0;
    }
    if (x[n - 1] == y[m - 1])
    {
        return dp[n][m] = 1 + lcs(dp, x, y, n - 1, m - 1);
    }
    else
    {
        return dp[n][m] = max(lcs(dp, x, y, n - 1, m), lcs(dp, x, y, n, m - 1));
    }
}

int lcsTabular(string x, string y, int n, int m)
{
    int dp[n + 1][m + 1];
    for (int i = 0; i <= m; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][m];
}
int main()
{
    string s1;
    string s2;
    cin >> s1 >> s2;
    int m = s1.length();
    int n = s2.length();
    int memo[100][100];
    for (size_t i = 0; i < 100; i++)
    {
        for (size_t j = 0; j < 100; j++)
        {
            memo[i][j] = -1;
        }
    }
    cout << "Memoized Soln " << lcs(memo, s1, s2, m, n) << endl;
    cout << "Tabular Soln " << lcsTabular(s1, s2, m, n);
    return 0;
}