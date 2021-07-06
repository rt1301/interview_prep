/****
 * Given a positive integer N, print all N bit binary numbers 
 * having more 1’s than 0’s for any prefix of the number.
 ****/
#include <bits/stdc++.h>
using namespace std;
void solve(string op, int ones, int zero, int n)
{

    if (n == 0)
    {
        cout << op << endl;
        return;
    }
    string op1 = op;
    op1.push_back('1');
    solve(op1, ones + 1, zero, n - 1);
    if (ones > zero)
    {
        string op2 = op;
        op2.push_back('0');
        solve(op2, ones, zero + 1, n - 1);
    }
    return;
}

int main()
{
    int n;
    cin >> n;
    int ones = 0;
    int zero = 0;
    string op = "";
    solve(op, ones, zero, n);
}