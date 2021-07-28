// Problem Statement
// https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1
#include <bits/stdc++.h>
using namespace std;
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> nums, int n)
    {
        vector<long long> v;
        stack<long long> s;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s.empty())
            {
                v.push_back(-1);
            }
            else if (!s.empty() && s.top() > nums[i])
            {
                v.push_back(s.top());
            }
            else if (!s.empty() && s.top() < nums[i])
            {
                while (!s.empty() && s.top() <= nums[i])
                {
                    s.pop();
                }
                if (s.empty())
                    v.push_back(-1);
                else
                    v.push_back(s.top());
            }
            s.push(nums[i]);
        }
        reverse(v.begin(), v.end());
        return v;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;
        vector<long long> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution obj;
        vector<long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res)
            cout << i << " ";
        cout << endl;
    }
    return 0;
} // } Driver Code Ends