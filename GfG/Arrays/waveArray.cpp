/****
 * Given a sorted array arr[] of distinct integers. 
 * Sort the array into a wave-like array and return it
 * In other words, arrange the elements into a sequence 
 * such that arr[1] >= arr[2] <= arr[3] >= arr[4] <= arr[5].....
 ****/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // arr: input array
    // n: size of array
    //Function to sort the array into a wave-like array.
    void convertToWave(vector<int> &arr, int n)
    {

        // Your code here
        bool flag = 1;
        for (int i = 0; i < n - 1; i++)
        {
            if (flag)
            {
                if (arr[i] < arr[i + 1])
                {
                    swap(arr[i], arr[i + 1]);
                }
            }
            else
            {
                if (arr[i] > arr[i + 1])
                {
                    swap(arr[i], arr[i + 1]);
                }
            }
            flag = flag ^ 1;
        }
    }
};