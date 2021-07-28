/****
 * Problem Statement - https://www.interviewbit.com/problems/k-largest-elements/
 ****/
#include <bits/stdc++.h>
using namespace std;
vector<int> Solution::solve(vector<int> &A, int B)
{
    priority_queue<int, vector<int>, greater<int>> minH;
    for (int i = 0; i < A.size(); i++)
    {
        minH.push(A[i]);
        if (minH.size() > B)
            minH.pop();
    }
    vector<int> ans;
    while (!minH.empty())
    {
        ans.push_back(minH.top());
        minH.pop();
    }
    return ans;
}