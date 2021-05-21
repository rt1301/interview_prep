class Solution
{
    vector<int> digits, f;
    void solve(string &ans, int n, int k)
    {
        if (n == 1)
        {
            ans += to_string(digits.back());
            return;
        }

        int index = k / f[n - 1];
        if (k % f[n - 1] == 0)
        {
            index--;
        }

        ans += to_string(digits[index]);
        digits.erase(digits.begin() + index);
        k -= f[n - 1] * index;
        solve(ans, n - 1, k);
    }

public:
    string getPermutation(int n, int k)
    {
        f.push_back(1);
        int fact = 1;
        for (int i = 1; i < n; i++)
        {
            fact *= i;
            f.push_back(fact);
        }

        for (int i = 1; i <= n; i++)
        {
            digits.push_back(i);
        }

        string ans = "";
        solve(ans, n, k);
        return ans;
    }
};