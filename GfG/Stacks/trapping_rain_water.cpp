/****
 * Given an array arr[] of N non-negative integers representing the height of blocks. 
 * If width of each block is 1, compute how much water can be trapped between the 
 * blocks during the rainy season. 
 * Problem Statement - https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1#
 ****/
#include <bits/stdc++.h>
using namespace std;
class Solution
{

    // Function to find the trapped water between the blocks.
public:
    int trappingWater(int arr[], int n)
    {
        // Code here
        int mxl[n];
        int mxr[n];
        mxl[0] = arr[0];
        for (int i = 1; i < n; i++)
        {
            mxl[i] = max(mxl[i - 1], arr[i]);
        }
        mxr[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            mxr[i] = max(mxr[i + 1], arr[i]);
        }

        int water[n];
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            water[i] = min(mxl[i], mxr[i]) - arr[i];
        }
        for (int i = 0; i < n; i++)
        {
            sum += water[i];
        }
        return sum;
    }
};
int main()
{

    int t;
    //testcases
    cin >> t;

    while (t--)
    {
        int n;

        //size of array
        cin >> n;

        int a[n];

        //adding elements to the array
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
    }

    return 0;
} // } Driver Code Ends