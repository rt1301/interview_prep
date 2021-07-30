#include <bits/stdc++.h>
using namespace std;
double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = A.size();
    int m = B.size();
    if (n > m)
    {
        return findMedianSortedArrays(B, A);
    }
    int l = 0;
    int r = n;
    int realMid = (n + m + 1) / 2;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        int leftASize = mid;
        int leftBSize = realMid - mid;
        int leftA = leftASize > 0 ? A[leftASize - 1] : INT_MIN;
        int leftB = leftBSize > 0 ? B[leftBSize - 1] : INT_MIN;
        int rightA = leftASize < n ? A[leftASize] : INT_MAX;
        int rightB = leftBSize < m ? B[leftBSize] : INT_MAX;

        if (leftA <= rightB && rightA >= leftB)
        {
            if ((m + n) % 2 == 0)
            {
                double ans = max(leftA, leftB) + min(rightA, rightB);
                return ans / (double)2;
            }
            else
            {
                return max(leftA, leftB);
            }
        }
        else if (leftA > rightB)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return 0.0;
}