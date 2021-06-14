/****
 * Given an array with n elements
 * Find the maximum sum in the array such that
 * the elements have no connectivity
 ****/
#include<bits/stdc++.h>
using namespace std;

int maxSum(int arr[], int n){
    int dp[n+1]; // dp table
    // dp[i] = Store the result for an array of i elements
    // Fill out the base conditions
    dp[1] = arr[0];
    dp[2] = max(arr[0], arr[1]);

    // Fill the rest of the dp table
    for(int i=3;i<=n;i++){
        // use the recurrence relation
        // res(n) = max(maxSum(arr,n-1), maxSum(arr,n-2)+arr[n-1]);
        dp[i] = max(dp[i-1],dp[i-2] + arr[i-1]);
    }
    return dp[n];
}
// Space Optimized Solution - O(1) Space
int solution(int arr[], int n){
    if(n == 1) return arr[0];
    int p0 = arr[0];
    int p1 = max(arr[0],arr[1]);
    int res = p1;
    for(int i=3;i<=n;i++){
        res = max(p1,p0+arr[i-1]); // max(dp[i-1],dp[i-2] + arr[i-1])
        p0 = p1;
        p1 = res;
    }
    return res;
}
int main(){
    int arr[] = {10,5,15,20};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<solution(arr,n);
    return 0;
}