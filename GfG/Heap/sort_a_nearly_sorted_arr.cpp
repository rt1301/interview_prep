/****
 * Given an array of n elements, where each element is at most k away 
 * from its target position, devise an algorithm that sorts in O(n log k) 
 * time. For example, let us consider k is 2, an element at index 7 in the 
 * sorted array, can be at indexes 5, 6, 7, 8, 9 in the given array.
 * Problem Statement - https://www.geeksforgeeks.org/nearly-sorted-algorithm/
 ****/
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    priority_queue<int, vector<int>, greater<int>> minH;
    for (int i = 0; i < n; i++)
    {
        minH.push(arr[i]);
        if (minH.size() > k)
        {
            cout << minH.top() << " ";
            minH.pop();
        }
    }
    while (!minH.empty())
    {
        cout << minH.top() << " ";
        minH.pop();
    }
    cout << endl;
    return;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}