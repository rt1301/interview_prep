/****
 * Given an array arr[] and a number K where K is smaller than size of 
 * array, the task is to find the Kth smallest element in the given array. 
 * It is given that all array elements are distinct.
 * Problem Statement - https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1#
 ****/
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k)
    {
        priority_queue<int> maxh;
        for (int i = 0; i <= r; i++)
        {
            maxh.push(arr[i]);
            if (maxh.size() > k)
                maxh.pop();
        }
        return maxh.top();
    }
};

// { Driver Code Starts.

int main()
{
    int test_case;
    cin >> test_case;
    while (test_case--)
    {
        int number_of_elements;
        cin >> number_of_elements;
        int a[number_of_elements];

        for (int i = 0; i < number_of_elements; i++)
            cin >> a[i];

        int k;
        cin >> k;
        Solution ob;
        cout << ob.kthSmallest(a, 0, number_of_elements - 1, k) << endl;
    }
    return 0;
} // } Driver Code Ends