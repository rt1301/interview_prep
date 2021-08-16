/****
 * Given an array of positive numbers, find the maximum sum of a subsequence 
 * with the constraint that no 2 numbers in the sequence should be adjacent in the array. 
 * So 3 2 7 10 should return 13 (sum of 3 and 10) or 3 2 5 10 7 
 * should return 15 (sum of 3, 5 and 7)
 ****/
#include<bits/stdc++.h>
using namespace std;
int dp[10000];
int solve(int arr[], int n){
    if(n<=0){
        return 0;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    if(n == 1){
        return dp[n] = max(arr[n-1] + solve(arr,n-1), solve(arr,n-1));
    }
    return dp[n] = max(arr[n-1] + solve(arr,n-2), solve(arr,n-1));
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<solve(arr,n);
    return 0;
}