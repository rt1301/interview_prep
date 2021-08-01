/****
 * Given an unsorted array Arr of size N of positive integers. 
 * One number 'A' from set {1, 2, …N} is missing and one number 'B' 
 * occurs twice in array. Find these two numbers.
 ****/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int *findTwoElement(int *arr, int n)
    {
        // code here
        static int ans[2] = {0};
        for (int i = 0; i < n; i++)
        {
            if (arr[abs(arr[i]) - 1] > 0)
                arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
            else
                ans[0] = abs(arr[i]);
        }
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > 0)
                ans[1] = i + 1;
        }
        return ans;
    }
};