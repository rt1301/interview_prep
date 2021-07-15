class Solution
{
public:
    unordered_map<pair<char, int>, int> dp;
    int countVowelStrings(int n)
    {
        // dp.clear();
        return solve(n, '\0');
    }
    int solve(int n, char last)
    {
        if (n == 0)
        {
            return 1;
        }
        if (dp.find({last, n}) != dp.end())
        {
            return dp[{last, n}];
        }
        int ans = 0;
        if (last == 'a' || !last)
        {
            ans += solve(n - 1, 'a') + solve(n - 1, 'e') + solve(n - 1, 'i') + solve(n - 1, 'o') + solve(n - 1, 'u');
        }
        else if (last == 'e')
        {
            ans += solve(n - 1, 'e') + solve(n - 1, 'i') + solve(n - 1, 'o') + solve(n - 1, 'u');
        }
        else if (last == 'i')
        {
            ans += solve(n - 1, 'i') + solve(n - 1, 'o') + solve(n - 1, 'u');
        }
        else if (last == 'o')
        {
            ans += solve(n - 1, 'o') + solve(n - 1, 'u');
        }
        else
        {
            ans += solve(n - 1, 'u');
        }
        return dp[{last, n}] = ans;
    }
};