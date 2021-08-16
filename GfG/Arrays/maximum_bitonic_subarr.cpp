/****
 * Given an array A[0 … n-1] containing n positive integers, a subarray A[i … j] 
 * is bitonic if there is a k with i <= k <= j such that 
 * A[i] <= A[i + 1] … = A[k + 1] >= .. A[j – 1] > = A[j]. 
 * Write a function that takes an array as argument and returns the length 
 * of the maximum length bitonic subarray. 
 ****/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> inc(n, 1);
    vector<int> dec(n, 1);
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            inc[i] += inc[i - 1];
        }
        else
        {
            inc[i] = 1;
        }
    }
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] > arr[i + 1])
        {
            dec[i] += dec[i + 1];
        }
        else
        {
            dec[i] = 1;
        }
    }
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, inc[i] + dec[i] - 1);
    }
    cout << ans;
    return 0;
}