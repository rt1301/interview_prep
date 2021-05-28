#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void printArr(vector<int> a)
    {
        for (int i = 0; i < (int)a.size(); i++)
        {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> merge(m + n, -1);
        int j = m - 1;
        for (int i = m + n - 1; i >= n; i--)
        {
            merge[i] = nums2[j];
            j--;
        }
        j = 0;
        int i = n;
        int k = 0;
        while (k < (m + n))
        {
            if (j == n || (i < (m + n) && merge[i] <= nums1[j]))
            {
                merge[k] = merge[i];
                i++;
                k++;
            }
            else
            {
                merge[k] = nums1[j];
                j++;
                k++;
            }
        }

        double median = 0;
        if ((m + n) % 2 != 0)
        {
            median = (merge[(m + n) / 2]);

            return median;
        }
        else
        {
            median = (merge[(m + n) / 2 - 1] + merge[(m + n) / 2]) / (double)2;
            return median;
        }
    }
};